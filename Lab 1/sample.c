#include <stdio.h>
#include <unistd.h>
int main()
{
    
    printf("Hello World\n");
    printf("After calling exec, PID of 'Sample': %d\n", getpid());
    return 0;
}