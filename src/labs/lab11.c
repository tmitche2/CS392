// Compute the sum of a file full of binary 16-bit integer data,
// parallel version.

// TODO: parallelize this program!
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

struct mmap_region {
	int fd;
	void *addr;
	size_t size;
};
int a = 0;
int b = 0;


size_t get_file_size(const char *filename);
void map_file_region(const char *filename, size_t size, struct mmap_region *region);
void unmap_file_region(struct mmap_region *region);
size_t i, size, num_elements;
uint16_t *data;
void* numelements1(void *unused){
	for (i = 0; i < num_elements/2; i++) {
		a += data[i];
	}
	pthread_exit(0);
}
void* numelements2(void *unused){
	for (i = num_elements-1; i >= num_elements/2; i--) {
		b += data[i];
	}
	pthread_exit(0);
}

int main(int argc, char **argv)
{
	uint64_t sum;
	struct mmap_region region;

	if (argc != 2) {
		fprintf(stderr, "Usage: sumu16 <input file>\n");
		exit(1);
	}

	// Find out how large the file is.
	size = get_file_size(argv[1]);
	printf("File is %lu bytes in size\n", size);

	// Each element (datum) is 16 bits.
	// Find out how many elements there are overall.
	num_elements = size / sizeof(uint16_t);

	// Map the file data into memory
	map_file_region(argv[1], size, &region);
	data = region.addr;

	// Compute the sum
	pthread_t thread1;
	pthread_t thread2;
	pthread_create(&thread1, NULL, numelements1, NULL);
	pthread_join(thread1, NULL);
	pthread_create(&thread2, NULL, numelements2, NULL);
	pthread_join(thread2, NULL);
	a = a + b;
	sum = 0ULL;
	for (i = 0; i < num_elements; i++) {
		sum += data[i];
	}
	//a = a + 1;
	printf("Sum is %lu\n", sum);
	printf("This is %lu\n", a);

	unmap_file_region(&region);

	return 0;
}

size_t get_file_size(const char *filename)
{
	struct stat file_info;

	if (stat(filename, &file_info) < 0) {
		fprintf(stderr, "Could not stat %s: %s\n", filename, strerror(errno));
		exit(1);
	}
	return (size_t)file_info.st_size;
}

void map_file_region(const char *filename, size_t size, struct mmap_region *region)
{
	region->size = size;

	// Open the file
	region->fd = open(filename, O_RDONLY);
	if (region->fd < 0) {
		fprintf(stderr, "Could not open %s: %s\n", filename, strerror(errno));
		exit(1);
	}

	// Map the file into memory.
	region->addr = mmap(NULL, (size_t)size, PROT_READ, MAP_PRIVATE, region->fd, (off_t)0);
	if (region->addr == MAP_FAILED) {
		fprintf(stderr, "Could not map %s: %s\n", filename, strerror(errno));
		exit(1);
	}
}

void unmap_file_region(struct mmap_region *region)
{
	munmap(region->addr, region->size);
	close(region->fd);
}


