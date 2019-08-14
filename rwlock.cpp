#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
using namespace std;
#include <iostream>


int num = 0;
pthread_rwlock_t rwlock = PTHREAD_RWLOCK_INITIALIZER;

void * reader(void *) {
    int time = 100000000;
    while (time--) {
        pthread_rwlock_rdlock(&rwlock);
        if (time % 1000 == 0) {
            // printf("print num in reader: num = %d\n", num);
            usleep(10);
        }
        pthread_rwlock_unlock(&rwlock);
    }
}

void * writer(void *) {
    int time = 100000000;
    while (time--) {
        pthread_rwlock_rdlock(&rwlock);
        num ++;
        pthread_rwlock_unlock(&rwlock);

    }
}

int main(int argc, char const *argv[])
{
    cout<<"start main function"<<endl;
    pthread_t thread1, thread2, thread3;
    pthread_create(&thread1, NULL, &reader, NULL);
    pthread_create(&thread2, NULL, &reader, NULL);
    pthread_create(&thread3, NULL, &writer, NULL);


    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    printf("print in main function: num= %d\n", num);


    return 0;
}

