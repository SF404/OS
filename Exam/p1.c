#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>

int main()
{
    int fd[2];
    char storage[100];
    char buffer[100];
    pipe(fd);
    int child1 = fork();

    if (child1 < 0)
    {
        printf("Failed to create child process\n");
        exit(1);
    }
    else if (child1 > 0)
    {
        printf("We are in child 1 process\n");
        dup2(fd[1], 1);
        char *arg[]={"ls", "-l", NULL};
        execvp("ls", arg);  
    }
    else
    {
        // wait(NULL);
        int child2 = fork();
        if(child2<0){
            printf("Failed to create child2\n");
            exit(1);
        }

        if (child2 > 0)
        {
            printf("We are in child 2 process\n");
            int file = open("output.txt", O_RDWR | O_CREAT);
            int length=read(fd[0], buffer, 100);
            write(fd[0], buffer, 100);
            write(file, buffer, 100);
        }
    }
    return 0;
}