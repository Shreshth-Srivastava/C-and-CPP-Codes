#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b){
    return (*(int *)a - *(int *)b);
}

int main(void){
    int arr[] = {5,4,3,2,1,10,9,7,6,8},n = sizeof(arr)/sizeof(arr[0]);
    qsort(arr,n,sizeof(arr[0]),cmp);
    for(int i = 0;i<n;i++) printf("%d ",arr[i]);
    return 0;
}

//Example

/*int comp (const void * elem1, const void * elem2) 
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}*/