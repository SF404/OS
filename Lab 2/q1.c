// Implement the process manipulation system calls like fork(), exec(), etc.
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<signal.h>

int main(){
    int f=fork(); // creating child process
    if (f<0){
        printf("Fork Failed! - Exit status: %d\n", f);
        exit(1);
    }
    else if(f==0){
        printf("Child Process\n");
    }
    else {
        printf("Parent process\n");
        int e = execlp("ps", "-l", "a", NULL);
    }
    return 0;
}