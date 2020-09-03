#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
int glob=0;
void* func(void *args){
int *id = (int *)args;
int loc=0;
static int stat=0;
glob++;
loc++;
stat++;
printf("Thread ID=%d, global=%d, local=%d, static=%d", *id, glob, loc, stat);
}
int main(){
pthread_t t1, t2, t3;
pthread_create(&t1, NULL, func, &t1);
pthread_create(&t2, NULL, func, &t2);
pthread_create(&t3, NULL, func, &t3);
pthread_exit(NULL);
return 0;
}