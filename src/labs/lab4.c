#include <stdio.h>

int fib(int n){
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

}