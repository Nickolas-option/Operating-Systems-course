#include <stdio.h>
#include <stdint.h>
#include <pthread.h>

void *myThread(void *args) {
    //code

    printf("pid = %d\n", (int)(intptr_t) args);
}

int main() {
    pthread_t thread[10];
    int i = 0;
    while (i < 10) {
    if (pthread_create((thread+i), NULL, myThread, (void*)(intptr_t) i)) {
        printf(">>ERROR IN CREATING Thread #%d!\n", i);
        pthread_exit(NULL);
        return 1;
    } else {
        pthread_join(thread[i], NULL);
        i++;
        printf(" >>Thread created!\n");
    }

    }
    i = 0;
 return 0;
}
