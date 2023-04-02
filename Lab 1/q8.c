#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
int main()
{
    int fd[2], length;
    char buffer[30];
    pipe(fd);

    int f1 = fork();
    if (f1 < 0)
    {
        printf("Failed to create child process\n");
        exit(1);
    }
    else if (f1 == 0)
    {
        printf("Passing message from child1 to stdout\n");
        dup2(fd[1], 1);
    }
    else
    {
        wait(NULL);
        printf("%s", buffer);
        int f2 = fork();
        if (f2 < 0)
        {
            printf("Failed to create child process\n");
            exit(1);
        }
        else if (f2 == 0)
        {
            dup2(fd[0], 0);
            scanf("%s", buffer);
            printf("The message from the first child is \"%s\"\n", buffer);
        }
        else{
            wait(NULL);
        }
    }
}