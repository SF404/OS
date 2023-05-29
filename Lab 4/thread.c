#include<pthread.h>
#include<stdio.h>
    int i=0;
void *testThread(void *tid){
    long *myId=(long*)tid;
    i++;
    printf("Hello from this thread is %ld Count: %d\n", *myId, i);
}

int main()
{
    pthread_t tid0;
    pthread_t tid1;
    pthread_t tid2;

    pthread_create (&tid0, NULL, testThread, (void*)&tid0);
    pthread_create (&tid1, NULL, testThread, (void*)&tid1);
    pthread_create (&tid2, NULL, testThread, (void*)&tid2);

    pthread_exit(NULL);
    return 0;
}