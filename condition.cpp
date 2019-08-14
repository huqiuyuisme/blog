#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
using namespace std;
#include <iostream>


int num = 0;
int max_num = 10;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void * producer(void *) {
    while (true) {
        pthread_mutex_lock(&mutex);
        while (num >= max_num) {        
            pthread_cond_wait(&cond, &mutex);
            printf("缓冲区满了， 等待消费者消费。。。\n");
        }
    num ++;
    pthread_cond_signal(&cond);
    printf("通知消费者。。。\n");
    pthread_mutex_unlock(&mutex);
    }
    
}

void * consumer(void *) {
    while (true) {
        pthread_mutex_lock(&mutex);
        while (num <= 0) {        
            pthread_cond_wait(&cond, &mutex);
            printf("缓冲区空了， 等待生产者生产。。。\n");
        }
    num --;
    pthread_cond_signal(&cond);
    printf("通知生产者。。。\n");
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

