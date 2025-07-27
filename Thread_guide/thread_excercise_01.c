#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>


void* calltao(void* arg){
    pthread_t tid = pthread_self();
    printf("id cua thread la: %lus\n", (unsigned long)tid);
    return NULL;

}
int main(){
    pthread_t thread01;
    pthread_t thread02;


    pthread_create(&thread01, NULL, calltao, NULL);
    pthread_create(&thread02, NULL, calltao, NULL);


    pthread_join(thread01, NULL);
    pthread_join(thread02, NULL);

}