#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv){
	setuid(0);
	execvp(argv[1], argv+1);
}

/**int fib(int n){
	//printf("I tried " + n);
	if (n<=1){
		return n;
	}
	else{
		return fib(n-1) + fib(n-2);
	}
}

int main(){
	char *args[] = {".fibo", NULL};
	execvp(args[0], args);

}*/