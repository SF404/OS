#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{

    int r = fork();
    if (r < 0)
    {
        printf("Error\n");
    }
    else if (r == 0)
    {
        printf("This is child process. The next instruction is 'close(1)'\n");
        int i = close(1); // closing stansdard Output 
        printf("Print after closing standard output file\n"); // Executed but not printed on screen
    }
    else
    {
        printf("This is the Parent Process\n");
    }
    return 0;
}