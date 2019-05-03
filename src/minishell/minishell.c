#define _POSIX_SOURCE
#include "my.h"
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
//function readline is fine, but the actual library is not

pid_t child;
//int child = -2;
//int pid = -2;
char* home;
//char * prompt = "";
char* file;
void controlC(int sig){
	if(child != -2){
		//my_str("in here");
		kill(child, SIGUSR1);
		//child = 0;
	}
	else{
		//my_str("nope not here");
		my_str("\n");
		my_str("Minishell: ");
		my_str(file);
		my_str(" $: ");

	}
}

void ex(){
    exit(0);
}

int main(){
	file=getcwd(NULL,0);
	while(1){
		home = getcwd(home, 2048);
		signal(SIGUSR1, SIG_IGN);
		signal(SIGINT, controlC);
		my_str("Minishell: ");
		my_str(home);
		//my_str(file);
		my_str(" $: ");
		char buff[2048];
		char c;
		child = -2;
		for( int i = 0; i<2048; i++){
			if(read(STDIN_FILENO, &c, 1)==1){
				if(c=='\n'||c=='\0'){
					buff[i]='\0';
					//my_str("in 1");
					break;
				}
				else{
					//my_str("in 2");
					buff[i]=c;
				}
			}
			else{
				//my_str("in 3");
				break;
				}
			}
		buff[2048]='\0';
		//my_str("in 4");
		char** input=my_str2vect(buff);
		int error=0;
		char* cmd=input[0];
		//my_str("in 5");
		if(cmd==NULL){
			//my_str("in 6");
			continue;
		}
		else if(my_strcmp(cmd, "cd")==0){
			//my_str("in 7");
			free(file);
			error=chdir(input[1]);
			file=getcwd(NULL,0);
			if(my_strcmp(input[1], NULL) ==0 || my_strcmp(input[1], "~") == 0){
				//my_str("in 8");
                    (void)chdir(getenv("HOME"));
                    file=getcwd(NULL,0);
                }
                else if((chdir(input[1]) == 0)){ }
                else if(error !=0){
					//my_str("\n");
					my_str(input[1]);
					my_str(" does not exist.");
					my_str("\n");
				}
            }
		else if(my_strcmp(cmd,"exit")==0){
			my_str("Exiting\n");
			exit(0);
		}
		else if(my_strcmp(cmd, "help")==0){
			my_str("Exit using the command exit.\nChange directory using the command cd filepath.\nGet help using the command help.\n");
		}
		else if(my_strcmp(cmd, "") == 0){
			my_str("in else if empty");
		}
		else{
			child=fork();
			if(child < 0){
				my_str("Fork error\n");
				exit(1);
			}
			if(child>0){
				//my_int(child);
				//my_str("waiting...");
				wait(NULL);
				//alarm(10);
			}
			else{
				signal(SIGINT,SIG_IGN);
                signal(SIGUSR1, ex);
				if(execvp(input[0], input)!=0){
					my_str("Not a valid input \n");
					exit(0);
				}
			}

		}
	}
	//exit(0);
	return 0;
}
