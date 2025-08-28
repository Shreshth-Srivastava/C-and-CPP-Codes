#include <stdio.h>

void  QuickSort(int *arr,int low,int high){
    if(low >= high) return;
    int s = low,e = high,m = s+(e-s)/2;
    int pivot = arr[m];
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
    int num_cases;
    scanf("%d",&num_cases);
    while(num_cases > 0){
    	int n,count = 1;
    	scanf("%d",&n);
    	if(n<4){
    	    printf("No");
    	    continue;
    	}
    	else{
    	    if(n&1){
    	        printf("No");
    	        continue;
    	    }
    	    int arr[n];
    	    for(int i = 0;i < n;i++){
    	        scanf("%d",arr[i]);
    	    }
    	    QuickSort(arr,0,n-1);
    	    for(int i = 1;i < n;i++){
    	        if(arr[i] == arr[i-1]) count++;
    	        else{
    	            if(arr[i] != arr[i-1]){
    	                if(count&1){
    	                    printf("No");
    	                    continue;
    	                }
    	                else{
    	                    count = 1;
    	                    continue;
    	                }
    	            }
    	        }
    	    }
    	}
    	printf("Yes");
    	printf("\n");
    	num_cases--;
    }
	return 0;
}

