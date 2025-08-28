#include<stdio.h>
int main(void){
    static int *p[]={10,11,12};
    printf("\n%p",p[0]);
    return 0;
}