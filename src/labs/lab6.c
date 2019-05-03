#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pid_t parent;
pid_t child;

void aqui(int sig){
	printf("Signal received\n");
	alarm(10);
}
void death(int sig){
	kill(child, SIGKILL);
	kill(parent, SIGKILL);
	alarm(10);
}
void controlC(int sig){
	if(kill(child, 0)!=0){
		kill(child, SIGUSR1);
	}
	else{
		printf("Goodbye!\n");
		kill(parent, SIGKILL);
	}
	alarm(10);
}
void controlZ(int sig){

	kill(child, SIGUSR1);
	alarm(10);
}
void deadKid(int sig){
	printf("Child exiting...\n");
	kill(child, SIGKILL);
	alarm(10);
}
int main(){
	parent = getpid();
	//int fd[2];
	//pipe(fd);
	pid_t pid = fork();
	alarm(10);
	if (pid > 0){
		//parent
		//alarm(10);
		signal(SIGINT, controlC);
		//pause();
		signal(SIGTSTP, controlZ);
		pause();
		signal(SIGALRM, death);
		pause();
		//wait(NULL);
	}
	else{
		//child
		child = getpid();
		signal(SIGUSR1, aqui);
		pause();
		signal(SIGUSR1, deadKid);
		pause();

	}
	return 1;
}