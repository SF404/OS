#include <stdio.h>
#include <unistd.h>
int main()
{
    // main process
    int x = 100; // variable x
    // creating child proess
    int p = fork();

    if (p < 0)
    {
        printf("Failed to create child process\n");
    }
    else if (p == 0)
    { //
        printf("------------------------\n");
        printf("Child Process is running\nvalue of x: %d\n", x);
        x = 30; // changing the value of x in child
    }
    else
    {
        printf("------------------------\n");
        printf("Parent Process is running\nvalue of x: %d\n", x);
        x = 40; // changing the value of x in parent
    }

    printf("The value of x after change: %d\n", x);
    printf("------------------------\n");

    return 0;
}

/*
    Outcomes:
    1. Child process copy all the variables of parent process.
    2. If we change the value variable in one process,
       the value of the variabe is unaffected in the other process

*/