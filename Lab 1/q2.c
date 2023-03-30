#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
    char buff1[20], buff2[20];
    int fd = open("file.txt", O_RDWR | O_CREAT); // Opening file
    printf("File Descriptor: %d\n", fd);         // printing file descriptor
    if (fd == -1)
    {
        printf("Failed to open file\n");
    }

    int p = fork(); // creating child process

    if (p < 0)
    {
        printf("Failed to create child process\n");
    }
    else if (p == 0)
    {
        printf("File Descriptor in Child Process: %d\n", fd);
        read(3, buff1, 10); // readig file in child process
        printf("Read Data in Child: %s\n", buff1);
    }
    else
    {
        printf("File Descriptor in Parent Process: %d\n", fd);
        read(3, buff2, 5); // reading file in parent process
        printf("Read Data in Parent: %s\n", buff2);
    }

    return 0;
}

/*
    Outcomes:
    1. Child process copy the file descriptor table of the parent process
    2. Both the process have access to the file descriptor of the opened file
    3. If parent and child process write the same file concurrently there is risk of data coruption, inconsisteny
       the result will be undeterministic.
*/