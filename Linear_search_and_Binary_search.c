///13
#include<stdio.h>
int main(void){
    int flag=0;
    int num=0;
    printf("\nEnter the number of elements you want to add in the list : ");
    scanf("%d",&num);
    int a[num];
    for(int i=0;i<num;i++){
        printf("\nEnter element number %d : ",i+1);
        scanf("%d",&(a[i]));
    }
    printf("\nGiven list :-");
    for(int i=0;i<num;i++) printf("\n%d",a[i]);
    int target=0;
    printf("\nEnter the element that you want to find in this list : ");
    scanf("%d",&target);   
    printf("---------------------------------------");
    printf("\n---------------------------------------");
    printf("\nWhich method would you like to choose to search in the list :-");
    printf("\n1. Linear Search");
    printf("\n2. Binary Search");
    printf("\n---------------------------------------");
    printf("\n---------------------------------------");
    printf("\nEnter your choice : ");
    scanf("%d",&flag);
    if(flag==1){
        int i=0,count=0;
        for(i;i<num;i++){
            if(a[i]==target){
                printf("\nTarget element found at index %d",i);
                printf("\nNumber of checks done : %d",count+1);
                break;
            }
            count++;
        }
        if(i==num) printf("\nTarget element not found");
    }
    else if(flag==2){
        int start=0,end=num-1,count=0;
        while(start<=end){
            int mid=start+((end-start)/2);
            if(a[mid]==target){
                printf("\nTarget element found at index %d",mid);
                printf("\nNumber of checks done : %d",count+1);
                break;
            }
            else if(a[mid]>target) end=mid-1;
            else start=mid+1;
            count++; 
        }
        if(start>end) printf("\nTarget element not found");
    }
    else printf("\n!!!Invalid Input!!!");
    return 0;
}