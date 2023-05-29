#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    int memorySizeMB = atoi(argv[1]);
    int arraySize = memorySizeMB * 1024 * 1024 / sizeof(int);

    int *array = (int *)malloc(arraySize * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Touch each entry of the array
    int i;
    while (1) {
        for (i = 0; i < arraySize; i++) {
            array[i] = i;
        }
        usleep(1000); // Sleep for 1 millisecond
    }

    free(array); // This line will never be reached

    return 0;
}
