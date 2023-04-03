// Implement the file manipulation system calls like open(), close(), etc.
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    int fd = open("sample.txt", O_RDWR);
    if (fd == -1)
    {
        printf("Failed to open file\n");
        exit(1);
    }
    char buffer[100];
    int length=write(fd, "this is a message\n", 18);
    lseek(fd, 0, SEEK_SET);
    read(fd, buffer, 18);
    printf("%s", buffer);
    close(fd);

    return 0;
}