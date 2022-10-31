#ifndef MUTEX_USAGE_H
#define MUTEX_USAGE_H

#include<pthread.h>
#include<unistd.h>
#include<stdio.h>

#define size 30

pthread_mutex_t mutex;


void* add(void *arg)
{
    pthread_mutex_lock(&mutex);
    int *arr = (int*)arg;
    for(int i=0;i<size;++i)
    {
        ++(arr[i]);
        usleep(100);
    }
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}
void* print(void *arg)
{
    pthread_mutex_lock(&mutex);
    int *arr = (int*)arg;
    for(int i=0;i<size;++i)
    {
        printf("%d ",arr[i]);
        usleep(80);
    }
    printf("\n");
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

void test_mutex()
{
    int arr[size]={0};

    for(int i=0;i<size;++i)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");

    pthread_t t1,t2;
    pthread_mutex_init(&mutex,NULL);

    pthread_create(&t1,NULL,add,&arr);
    pthread_create(&t2,NULL,print,&arr);


    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    pthread_mutex_destroy(&mutex);
    printf("\n");
}





















#endif