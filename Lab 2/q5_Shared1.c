// This program creates a shared memory segment, attaches itself to it and then writes some content into the shared memory segment.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>
int main()
{
    int i;
    void *shared_memory;
    char buff[100];
    int shmid;
    // creates shared memory segment with key 2345, having size 1024 bytes.
    // 0666 are the permisions on the shared segment
    shmid = shmget((key_t)2345, 1024, 0666 | IPC_CREAT);
    printf("Key of shared memory is %d\n", shmid);
    // process attached to shared memory segment
    shared_memory = shmat(shmid, NULL, 0);
    printf("Process attached at %p\n", shared_memory);
    printf("Enter some data to write to shared memory\n");
    read(0, buff, 100);          // get some input from user
    strcpy(shared_memory, buff); // data written to shared memory
    printf("You wrote : %s\n", (char *)shared_memory);
}