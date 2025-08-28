#include <stdio.h>

int BinarySearch(int *arr,int N,int target){
    int start = 0,end = N-1;
    while(start <= end){
        int mid = start + (end-start)/2;
        if(arr[mid] == target) return mid;
        else{
            if(arr[mid] > target) end = mid-1;
            else start = mid+1;
        }
    }
    return -1;
}

void QuickSort(int *arr,int low,int high){
    if(low >= high) return;
    int s = low,e = high,m = s + (e-s)/2,pivot = arr[m];
    while(s <= e){
        while(arr[s] < pivot) s++;
        while(arr[e] > pivot) e--;
        if(s <= e){
            int temp = arr[s];
            arr[s] = arr[e];
            arr[e] = temp;
            s++;
            e--;
        }
    }
    QuickSort(arr,low,e);
    QuickSort(arr,s,high);
}

int main(void) {
	int n;
	scanf("%d",&n);
	while(n--){
	    int N,target,a;
	    scanf("%d",&N);
	    int arr[N];
	    for(int i = 0;i < N;i++){
	        scanf("%d",&arr[i]);
	    }
	    scanf("%d",&a);
	    target = arr[a-1];
	    printf("\n");
	    QuickSort(arr,0,N-1);
	    int result = BinarySearch(arr,N,target);
	    printf("%d",result+1);
	}
	return 0;
}

