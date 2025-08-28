#include<stdio.h>

int Index(int *arr,int N,int index){
    int target = arr[index];
    for(int i = index+1;i < N;i++){
        if(arr[i] != target) return i-1; 
    }
    return N-1;
}

int main(void){
    int n;
    scanf("%d",&n);
    while(n--){
        int N;
        scanf("%d",&N);
        int arr[N];
        for(int i = 0;i < N;i++){
            scanf("%d",&arr[i]);
        }
        int a;
        for(int i = 0;i < N;i++){
            a = Index(arr,N,i);
            arr[i] = N-1-a;
        }
        for(int i = 0;i < N;i++) printf("%d ",arr[i]);
        printf("\n");
    }
    return 0;
}