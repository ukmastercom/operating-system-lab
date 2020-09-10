#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
 int main(){
int a,i=0;
a=fork();
if(a==0){
for(i=0;i<=2;i++){
printf("CHILD\n");
exit(0);
}
else{
for(i=1;i<=2;i++){
printf("PARENT\n");
}
exit(0);
return 0;
}