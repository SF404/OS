// Implement the system calls for Inter-Process communication.
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
int main()
{
    int fd[2];
    char storage[100];
    pipe(fd);
    int f = fork();

    if (f < 0)
    {
        printf("Failed to create child process\n");
        exit(1);
    }
    else if (f > 0)
    {
        write(fd[1], "This is the message\n", 21);
    }
    else
    {
        int i = read(fd[0], storage, sizeof(storage));
        write(1, storage, strlen(storage));
    }
    return 0;
}