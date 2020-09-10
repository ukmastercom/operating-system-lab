#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <semaphore.h>
#include<pthread.h>

#define true 1
#define false 0

int a, b;
sem_t sem;
void* no() {
    while(true) {
        printf("Enter two numbers: ");
        scanf("%d %d", &a, &b);

        sem_post(&sem);
        sleep(4);
    }
}

void* sumo() {
    while(true) {
        sem_wait(&sem);
        printf("Sum = %d\n", a+b);
    }
}

int main() {
    pthread_t t1;
    pthread_t t2;

    sem_init(&sem, 0, 0);

    pthread_create(&t1, NULL, no, NULL);
    pthread_create(&t2, NULL, sumo, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Both threads are over\n");
    sem_destroy(&sem);

    return 0;
}