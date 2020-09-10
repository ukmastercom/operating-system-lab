#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <semaphore.h>

int flag[2];
int turn,count=0,mode=0;
const int MAX = 1000000;

void lock_init()
{
    flag[0] = flag[1] = 0;
    turn = 0;
}
void lock(int a)
{
    flag[a] = 1;
    turn = 1-a;
    while (flag[1-a]==1 && turn==1-a) ;
}

void unlock(int a)
{
    flag[a] = 0;
}
void* process(void *s)
{
    int i = 0;
    int a = (int *)s;
    printf("Process no : %d\n", a);

    if(mode == 1)
        lock(a);
    for (i=0; i<MAX; i++)
        count++;

    if(mode == 1)
        unlock(a);
}
void main()
{
    pthread_t t1,t2,t3,t4;

    printf("\nWithout Lock: FIRST\n");
    pthread_create(&t1, NULL, process, (void*)0);
    pthread_create(&t2, NULL, process, (void*)1);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("Count(ACTUAL): %d and Count(EXPECTED): %d\n",count, MAX*2);

    printf("\nwith Lock\n");
    count = 0;
    mode = 1;
    lock_init();

    pthread_create(&t3, NULL, process, (void*)0);
    pthread_create(&t4, NULL, process, (void*)1);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);

    printf("Count(ACTUAL): %d and Count(EXPECTED): %d\n",count, MAX*2);
}