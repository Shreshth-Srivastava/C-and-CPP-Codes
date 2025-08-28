#include<stdio.h>

// int Fight(int *arr,int N,int H,int X){
//     int b = H;
//     for(int i = 0;i < N;i++){
//         if(arr[i] <= X) continue;
//         else{
//             if(arr[i] < b){
//                 b = b - arr[i];
//                 continue;
//             }
//             else return -1;
//         }
//     }
//     return 1;
// }

void QuickSort(int *nums, int low, int high){
    if(low >= high) return;
    int s = low;
    int e = high;
    int m = s + (e-s)/2;
    int pivot = nums[m];
    while(s <= e){
        while(nums[s]<pivot) s++;
        while(nums[e]>pivot) e--;
        if(s <= e){
            int temp = nums[s];
            nums[s] = nums[e];
            nums[e] = temp;
            s++;
            e--;
        }
    }
    QuickSort(nums,low,e);
    QuickSort(nums,s,high);
}

int Fight(int *arr,int N,int H,int X,int *flag,int *index){
    int b = H;
    for(int i = 0;i < N;i++){
        if(arr[i] <= X) continue;
        else{
            if(arr[i] < b){
                b = b - arr[i];
                continue;
            }
            else{
                return X = arr[*index];
            }
        }
    }
    *flag = 1;
    return X;
}

int main(void){
    int n;
    scanf("%d",&n);
    while(n--){
        int N,H,X = 0,flag = 0,index=0;
        scanf("%d",&N);
        scanf("%d",&H);
        int arr[N];
        for(int i = 0;i < N;i++){
            scanf("%d",&arr[i]);
        }
        QuickSort(arr,0,N-1);
        while(flag == 0){
            X = Fight(arr,N,H,X,&flag,&index);
            index++;
        }
        printf("%d\n",X);
    }
    return 0;
}