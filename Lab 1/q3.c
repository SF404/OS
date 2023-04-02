#include <stdio.h>
#include <unistd.h>
int main()
{
    int f = fork();
    if (f < 0)
    {
        printf("Error creating Child Process\n");
    }
    else if (f == 0)
    {
        // Child process
        printf("Hello\n");
    }
    else
    {
        // Parent process
        sleep(1); // Pause the execution for 1 sec
        printf("GoodBye\n");
    }
}