#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>


long long int counter = 0;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void* add_func(void* arg){
    int thread_id = *(int*)arg;
    for (size_t i = 0; i < 1000000; i++)
    {
        usleep(10);
        pthread_mutex_lock(&lock);
        counter++;
        printf("thread: %d, %lld\n", thread_id, counter);
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main(){
    pthread_t lu1, lu2, lu3;
    int id1 = 1, id2 = 2, id3 = 3;

    pthread_create(&lu1, NULL, add_func, &id1);
    pthread_create(&lu2, NULL, add_func, &id2);
    pthread_create(&lu3, NULL, add_func, &id3);

    pthread_join(lu1, NULL);
    pthread_join(lu2, NULL);
    pthread_join(lu3, NULL);

    pthread_mutex_destroy(&lock);




}