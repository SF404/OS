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
        // waitpidpid waitpids untill the specific child process terminates.
        // waitpidpid returns the pid of child Process, if it fails it return -1.
        int k = waitpid(f, NULL, 0);
        printf("I am Parent Process\n");
        printf("PID of parent process: %d\n", getppid());

        printf("PID of Child process Returned by waitpid System call: %d\n", k);
    }
}

/*
    Outcomes:
        1. waitpidpid system call waits the untill any one of its child process terminates.
        2. waitpid system call returns pid of the child process.
        3. If waitpid system call fails it returns -1, such as in case when no child exist.
        4. If we waitpid in the child process, the child process waits untill any one of its child process terminates.
           If no further child process of the child process exist waitpid returns -1.
        5. Waitpid is usefull when parent has to wait for specfic child to change its state (by default terminate).
*/