#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
/**Requirements: Key starting at 5, increases by 2 every 3 characters
Counter, outside of the loop increase by 2
Inside the for loop- check if character is "!" or " "
Printf("Decrypted: %s")
*/

int main(){
	int key = 5;
	int fd = open("encrypted.txt", O_RDONLY);
	char buff[3];//Buffer
	int rd = 2;//read(fd, buff, 3); //Read
	int fd2 = open("solution.txt", O_WRONLY);
	//int wrt = write(fd2, 3);
	while(rd > 0){
		rd = read(fd, buff, 3);
		for(int i=0;i<rd;i++){
			if (buff[i] = '!' || ' '){}
			else{ //printf("I got here %c\n",buff[i]);
				 //buff[i]=buff[i]- key;
				for (int j = 0; j < key; j++) {
					buff[i] -= 1;
					if (buff[i] == 'a'-1)
						buff[i] = 'z';
					else if (buff[i] == 'A'-1)
						buff[i] = 'Z';
				}
			}

		write(fd2 , buff, 3);
		}
		

		key += 2;
	}


	//printf(buff);

}