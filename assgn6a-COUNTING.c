#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <semaphore.h>
#include<pthread.h>

sem_t s;
void handlerfunction(int signal)
{
    sem_post(&s);
}
void *function(void *args)
{
    sem_wait(&s);
    printf("WAIT\n");
}

int main()
{
    int ok = sem_init(&s, 0, 0);
    if (ok == -1) {
       perror("THIS IS AN ERROR");
       return 1;
    }
    signal(SIGINT, handlerfunction);

    pthread_t t1;
    pthread_create(&t1, NULL, function, NULL);
    pthread_exit(NULL);
}