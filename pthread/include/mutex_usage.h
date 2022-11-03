#ifndef MUTEX_USAGE_H
#define MUTEX_USAGE_H

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/syscall.h>

#define SIZE 100000

pthread_mutex_t mutex;

void *add(void *arg)
{
// #define USE_MUTEX
#ifdef USE_MUTEX
    pthread_mutex_lock(&mutex);
#endif

    int *p = (int *)arg;
    for (int i = 0; i < SIZE; ++i)
    {
        ++(*p);
    }

#ifdef USE_MUTEX
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
#endif
}
void test_mutex()
{

    int count = 0;

    printf("init num: %d\n", count);

    pthread_t t1, t2;
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&t1, NULL, add, &count);
    pthread_create(&t2, NULL, add, &count);


    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&mutex);

    printf("result: %d\n", count);
    printf("real : %d\n", SIZE * 2);
}

#endif