#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(void){
	int var;
	pid_t pid;
	printf("Before fork.\n");
	pid = fork();
	printf("After fork.\n");
	if(pid == 0){
		printf("this is son.\n");
	} else{
		printf("this is father.\n");
	}
	return 0;
}
