#include<stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
int main() 
{   
    int pid = fork(); 
    if (pid > 0) 
        printf("parent process"); 
    else if (pid == 0) 
    { 
        sleep(50); 
        printf("child process"); 
    }
    return 0; 
} 
