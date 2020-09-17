#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <math.h>
#include <string.h>

#define max_items 5
#define buffer_size 5


sem_t empty;
sem_t full;
int in=0, out=0;
int buffer[buffer_size];
pthread_mutex_t mutex;

void *producer(void *args){
int item,i=0;
for(i=0;i<max_items;i++){
item = rand();
sem_wait(&empty);
pthread_mutex_lock(&mutex);
buffer[in] = item;
printf("Producer %d : insert item = %d at %d\n" *((int *)args), buffer[in], in);
in = (in+1)%buffer_size;
pthread_mutex_unlock(&mutex);
sem_post(&full);
}
}


void *consumer(void *args){
int i=0;
for(i=0;i<max_items;i++){
sem_wait(&full);
pthread_mutex_lock(&mutex);
int item = buffer[out];
printf("Consumer %d : Remove item = %d from %d\n",*((int *)args),item,out);
out = (out+1)%buffer_size;
pthread_mutex_unlock(&mutex);
sem_post(&empty);
}
}


int main(){
int i=0;
pthread_t pro[5],con[5];
pthread_mutex_init(&mutex, NULL);
sem_init(&empty,0,buffer_size);
sem_init(&full,0,0);
int a[5] = {1,2,3,4,5}
for(i=0;i<5;i++){
pthread_create(&pro[i], NULL, (void *)producer, (void *)&a[i]);
}
for(i=0;i<5;i++){
pthread_create(&pro[i], NULL, (void *)consumer, (void *)&a[i]);
}
for(i=0;i<5;i++){
pthread_join(pro[i], NULL);
}
for(i=0;i<5;i++){
pthread_join(con[i], NULL);
}
pthread_mutex_destroy(&mutex);
sem_destroy(&empty);
sem_destroy(&full);
return 0;
}