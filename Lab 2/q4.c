// Signal 
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
void handler(int sig)
{
    printf(" Caught signal %d\n", sig);
}
  
int main()
{
    signal(SIGINT, handler);
    while (1) ;
    return 0;
}
