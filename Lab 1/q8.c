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
        write(fd[1], "This is the message\n", 21);
    }
    else
    {
        int f2 = fork();
        if (f2 < 0)
        {
            printf("Failed to create child process\n");
            exit(1);
        }
        else if (f2 == 0)
        {
            read(fd[0], buffer, 21);
            printf("The message from the first child is: ");
            // write(1, buffer, 21);
            printf("%s\n", buffer);
        }
        else{
            wait(NULL);
        }
    }
}