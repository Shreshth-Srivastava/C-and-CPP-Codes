///12(b)
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
    for(int j=1;j<b;j++){
        int key=a[j];
        int i=j-1;
        while(i>=0 && a[i]>key){
            int k=0;
            k=a[i+1];
            a[i+1]=a[i];
            a[i]=k;
            i--;
        }
        key=a[i+1];
    }
    printf("\nSorted array in ascending order using insertion sort is as follows :-");
    for(int i=0;i<b;i++){
        printf("\n%d",a[i]);
    }
    return 0;
}