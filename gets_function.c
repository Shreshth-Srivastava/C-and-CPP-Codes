#include<stdio.h>
#include<string.h>

int main(void){
    char name[80];
    printf("\nEnter your name: ");
    gets(name);
    for(int i=0;i<strlen(name);i++) printf("%c",name[i]);
    return 0;
}