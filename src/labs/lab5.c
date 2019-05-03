#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include <strings.h>
/*Write my_malloc(int) which keeps track of location of the program
break, uses sbrk(2) to increment it, and returns a pointer to newly
allocated block of memory*/

void* my_malloc(int n){
	return sbrk(n);
}
void* my_calloc(int num, int size){
	void* toRet = my_malloc(num*size);
	bzero(toRet, num*size);
	return toRet;
}
void* my_free(void* x){
	
}