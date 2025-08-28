#include<stdio.h>

int Push(int arr[],int p){
    int x = 0;
    if(p == 100) printf("\n!!Stack Overflow!!\n");
    else{
        printf("\nEnter the value that you want to add in the stack: ");
        scanf("%d",&x);
        arr[p] = x;
        p++;
    }
    return p;
}
int Pop(int arr[],int p){
    if(p == 0) printf("\n!!Stack Underflow!!");
    else{
        p--;
    }
    printf("\n");
    return p;
}
void View(int arr[],int p){
    if(p == 0) printf("\nNo elements in the Stack");
    else{
        if(p<=100){
            printf("\n%d <--Top",arr[p-1]);
            for(int i=p-2;i>=0;i--){
                printf("\n%d",arr[i]);
            }
        }
    }
    printf("\n");
}

int main(void){
    int arr[100];
    int flag = 1, a = 0, p = 0;
    while(flag != 0){
        printf("\nStack Operations: ");
        printf("\n1. View");
        printf("\n2. Push");
        printf("\n3. Pop");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&a);
        if(a == 1) View(arr,p);
        if(a == 2) p = Push(arr,p);
        if(a == 3) p = Pop(arr,p);
        if(a == 4) flag = 0;
    }
    return 0;
}