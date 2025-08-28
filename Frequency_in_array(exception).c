///14
#include<stdio.h>
int main(void){
    int size,target;
    printf("\nEnter size of the array : ");
    scanf("%d",&(size));
    int a[size];
    int b[]={};
    for(int i=0;i<size;i++){
        printf("\nEnter element no. %d : ",(i+1));
        scanf("%d",&(a[i]));
    }
    printf("\nInputed array is as follows : ");
    for(int i=0;i<size;i++){
        printf("\n%d",a[i]);
    }
    printf("\nEnter the element that you want to find  : ");
    scanf("%d",&(target));
    int count=0;
    for(int i=0;i<size;i++){
        if(a[i]==target){
            b[count]=i;
            count++;
        }
    }
    printf("\nTarget element found at indexes : ");
    for(int i=0;i<=count;i++){
        printf("\n%d",b[i]);
    }
    printf("\nWith frequency : %d",count);
    return 0;
}