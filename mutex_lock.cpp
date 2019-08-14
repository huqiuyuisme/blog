#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
using namespace std;
#include <iostream>


int num = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void * producer(void *) {
    int time = 10000000;
    while (time--) {
        pthread_mutex_lock(&mutex);
        num ++;
        pthread_mutex_unlock(&mutex);
    }
}

void * consumer(void *) {
    int time = 10000000;
    while (time--) {
        pthread_mutex_lock(&mutex);
        num --;
        pthread_mutex_unlock(&mutex);
    }
}

int main(int argc, char const *argv[])
{
    cout<<"start main function"<<endl;
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, &producer, NULL);
    pthread_create(&thread2, NULL, &consumer, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("print in main function: num= %d\n", num);


    return 0;
}

