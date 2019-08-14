#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
using namespace std;
#include <iostream>


int num = 0;
pthread_spinlock_t spin_lock;

void * producer(void *) {
    int time = 100000000;
    while (time--) {
        pthread_spin_lock(&spin_lock);
        num ++;
        pthread_spin_unlock(&spin_lock);

    }
}

void * consumer(void *) {
    int time = 100000000;
    while (time--) {
        pthread_spin_lock(&spin_lock);
        num --;
        pthread_spin_unlock(&spin_lock);

    }
}

int main()
{
    cout<<"start main function"<<endl;
    pthread_t thread1, thread2;
    pthread_spin_init(&spin_lock, 0);
    pthread_create(&thread1, NULL, &producer, NULL);
    pthread_create(&thread2, NULL, &consumer, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("print in main function: num= %d\n", num);
    return 0;
}

