#include <stdio.h>

// void  QuickSort(int *arr,int low,int high){
//     if(low >= high) return;
//     int s = low,e = high,m = s+(e-s)/2;
//     int pivot = arr[m];
//     while(s <= e){
//         while(arr[s] < pivot) s++;
//         while(arr[e] > pivot) e--;
//         if(s <= e){
//             int temp = arr[s];
//             arr[s] = arr[e];
//             arr[e] = temp;
//             s++;
//             e--;
//         }
//     }
//     QuickSort(arr,low,e);
//     QuickSort(arr,s,high);
// }

// int main(void) {
// 	int n,count = 1;
// 	printf("\nEnter the value of n: ");
// 	scanf("%d",&n);
// 	if(n<4){
// 	    printf("\nNo");
// 	    return 0;
// 	}
// 	else{
// 	    if(n&1){
// 	        printf("\nNo");
// 	        return 0;
// 	    }
// 	    int arr[n];
// 	    for(int i = 0;i < n;i++){
// 			printf("\nEnter value of arr[%d]: ",i);
// 	        scanf("%d",&arr[i]);
// 	    }
// 	    QuickSort(arr,0,n-1);
// 	    for(int i = 1;i < n;i++){
// 	        if(arr[i] == arr[i-1]) count++;
// 	        else{
// 	            if(arr[i] != arr[i-1]){
// 	                if(count&1){
// 	                    printf("\nNo");
// 	                    return 0;
// 	                }
// 	                else{
// 	                    count = 1;
// 	                    continue;
// 	                }
// 	            }
// 	        }
// 	    }
// 	}
// 	printf("\nYes");
// 	return 0;
// }

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
    while(num_cases--){
    	int n,count = 1;
    	scanf("%d",&n);
    	// if(n<4){
    	//     printf("No\n");
    	//     continue;
    	// }
    	// else{
    	    // if(n&1){
    	    //     printf("No\n");
    	    //     continue;
    	    // }
    	    int arr[n];
    	    for(int i = 0;i < n;i++){
    	        scanf("%d",&arr[i]);
    	    }
    	    QuickSort(arr,0,n-1);
    	    for(int i = 1;i < n;i++){
    	        if(arr[i] == arr[i-1]) count++;
    	        else{
    	            if(arr[i] != arr[i-1]){
    	                if(count&1) break;
    	                else{
    	                    count = 1;
    	                    continue;
    	                }
    	            }
    	        }
    	    }
			if(count&1){
    	        printf("No\n");
    	        continue;
    	    }
    	// }
    	printf("Yes\n");
    }
	return 0;
}