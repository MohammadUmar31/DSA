#include<pthread.h>
#include<stdio.h>
#include <semaphore.h>
#include<unistd.h>
#include<stdlib.h>

#define NUM_THREADS 5

sem_t semaphore;

void* accessResource(void* arg){
    printf("Thread %d is waiting to access resource.\n", *(int*)arg);
    sem_wait(&semaphore);
    printf("Thread %d is accessing the resource.\n", *(int*)arg);
    sleep(2);
    printf("Thread %d has finished accessing the resource.\n", *(int*)arg);
    sem_post(&semaphore);
    free(arg);
    return NULL;
}

int main(){
    sem_init(&semaphore, 0, 3);
    pthread_t threads[NUM_THREADS];
    for(int i = 0; i < NUM_THREADS; i++){
        int* threadId = malloc(sizeof(int));
        *threadId = i;
        pthread_create(&threads[i], NULL, accessResource, threadId);
    }
    for(int i = 0; i < NUM_THREADS; i++){
        pthread_join(threads[i], NULL);
    }
    sem_destroy(&semaphore);
    return 0;
}
