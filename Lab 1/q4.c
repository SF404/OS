#include <stdio.h>
#include <unistd.h>
int main()
{
    printf("Before Exec, PID before calling exec: %d\n", getpid());
    char *args[] = {"./sample", NULL};
    int i = execv(args[0], args);
    printf("After Exec, exec failed!%d\n", i);
    return 0;
}