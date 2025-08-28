///12(a)
#include<stdio.h>
int main(void){
    int b;
    printf("Enter the numbers of elements you want to enter in the array : ");
    scanf("%d",&b);
    int a[b];
    for(int i=0;i<b;i++){
        printf("\nEnter element no. %d : ",(i+1));
        scanf("%d",&(a[i]));
    }
    for(int i=0;i<b;i++){
        for(int j=b-1;j>=(i+1);j--){
            if(a[j]<a[j-1]){
                int k=0;
                k=a[j];
                a[j]=a[j-1];
                a[j-1]=k;
            }
        }
    }
    printf("\nSorted array in ascending order using bubble sort is as follows :-");
    for(int i=0;i<b;i++){
        printf("\n%d",a[i]);
    }
    return 0;
}