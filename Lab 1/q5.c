#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    int f = fork();
    if (f < 0)
    {
        printf("Error creating Child Process\n");
    }
    else if (f == 0)
    {
        printf("I am Child Process\n");
        printf("PID of child process: %d\n", getpid());
    }
    else
    {
        // wait returns the pid of child Process, if it fails it return -1
        int k = wait(NULL);
        printf("I am Parent Process\n");
        printf("PID of parent process: %d\n", getppid());

        printf("PID of Child process Returned by wait System call: %d\n", k);
    }
}

/*
    Outcomes:
        1. Wait system call waits the untill any one of its child process terminates.
        2. Wait system call returns pid of the child process.
        3. If wait system call fails it returns -1, such as in case when no child exist.
        4. If we wait in the child process, the child process waits untill any one of its child process terminates.
           If no further child process of the child process exist wait returns -1.
*/