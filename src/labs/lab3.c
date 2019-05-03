#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
/**Create a process that splits off into two processes.
The processes must do the following- Directions on canvas */


int main(){
	//do a thing
	//do more things
	char buff[32];
	int fd[];
	pid_t pid;
	pid = fork();
	stdin = filedescriptor 0;
	char *fgets(char *str, 50, stdin);
	while(1){
		if (pid < 0){
			//error, inspect errno
		}
		else if(pid == 0){
			//child
			write(fd[0], buff, 32);
			break;
		}
		else{
			//parent
			for(int i = 0; i < 32; i++){
				buff[i] = NULL;
			}
			read(fd[1], buff, 32);

			printf("%s\n", buff);


			wait(NULL);
			break;
		}
	}




	return 0;
}