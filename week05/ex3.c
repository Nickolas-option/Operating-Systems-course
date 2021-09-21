#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int buffer = 0;
pthread_cond_t cConsumer;
pthread_cond_t cProducer;
pthread_t produc;
pthread_t consum;
pthread_mutex_t lock;

void *producer(void *arg) {
    int i = 0;
    while (1) {
        pthread_mutex_lock(&lock);
        while (buffer != 0) {
            pthread_cond_wait(&cProducer, &lock);
        }
        buffer = i;
        pthread_cond_signal(&cConsumer);
        pthread_mutex_unlock(&lock);
        ++i;
    }
    pthread_exit(0);
}

void *consumer(void *arg) {
    int i = 0;
    while (1) {
        pthread_mutex_lock(&lock);
        while (buffer == 0) {
            pthread_cond_wait(&cConsumer, &lock);
        }
        buffer = 0;
        pthread_cond_signal(&cProducer);
        pthread_mutex_unlock(&lock);
        ++i;
        printf("%d is produced\n", i);
    }
    pthread_exit(0);
}

int main() {
    pthread_mutex_init(&lock, 0);
    pthread_cond_init(&cProducer, 0);
    pthread_cond_init(&cConsumer, 0);
    pthread_create(&produc, 0, producer, 0);
    pthread_create(&consum, 0, consumer, 0);
    pthread_join(produc, 0);
    pthread_join(consum, 0);
    pthread_cond_destroy(&cProducer);
    pthread_cond_destroy(&cConsumer);
    pthread_mutex_destroy(&lock);
}
