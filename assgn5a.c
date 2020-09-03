#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
int ans[1000];
void *fibo(void* args);
void parent(int *n){
printf("Enter the number of terms: " );
scanf("%d",&(*n));
return;
}
void *fibo(void* args)
{
int *p;
p=(int*)args;
int n=*p;
int a=0,b=1,c=0;
for (int i=0;i<n;i++)
{
if (i<=1)
c=i;
else
{
c=a+b;
a=b;
b=c;
}
ans[i]=c;
}
return NULL;
}

int main()
{
pthread_t t;
int n;
pthread_attr_t attr;
pthread_attr_init(&attr);
parent(&n);
pthread_create (&t , &attr , fibo,(void*)&n);
pthread_join(t,NULL);
printf("First %d terms are : ",n);
for(int i = 0; i <n; i++) {
printf("%d ",ans[i]);
}
return 0;
}