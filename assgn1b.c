#include <stdio.h>
#include <sys/types.h> 
#include <unistd.h> 

void func() 
{ 
    if (fork() == 0) 
        printf("Hello I am child!\n"); 
    else
        printf("Hello!\n"); 
}

int main()
{
    func();
    return 0;
}