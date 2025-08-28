#include<stdio.h>
void main(void){
    int a;
    printf("\nEnter your input : ");
    scanf("%d",&a);
    static char *err[]={"ABC","DEF","GHI"};
    printf("\n%s",err[a]);
}