#include<stdio.h>

void SortTwoDim(int *arr,int rows,int cols){
    for(int i = 0;i < (cols*rows)-cols;i += cols){
        for(int j = i+cols;j>0;j -= cols){
            if(arr[j]<arr[j-cols]){
                int temp;
                for(int k = 0;k<cols;k++){
                    temp = arr[j+k];
                    arr[j+k] = arr[j-cols+k] ;
                    arr[j-cols+k] = temp;
                }
            }
        }
    }
}

int main(void){
    int arr[4][4] ={{13,14,15,16},{9,10,11,12},{5,6,7,8},{1,2,3,4}};
    SortTwoDim((int *)arr,4,4);
    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++) printf("%d  ",arr[i][j]);
        printf("\n");
    }
    return 0;
}

// void SortTwoDim(int *arr,int rows,int cols){
//     for(int i = 0;i < (2*rows)-2;i += 2){
//         for(int j = i+2;j>0;j -= 2){
//             if(arr[j]<arr[j-2]){
//                 int temp1 = arr[j],temp2 = arr[j+1];
//                 arr[j] = arr[j-2];
//                 arr[j+1] = arr[j-1];
//                 arr[j-2] = temp1;
//                 arr[j-1] = temp2;
//             }
//         }
//     }
// }

// int main(void){
//     int arr[5][2] ={{5,6},{3,4},{1,2},{7,8},{9,10}};
//     SortTwoDim((int *)arr,5,2);
//     for(int i = 0;i<5;i++){
//         for(int j = 0;j<2;j++) printf("%d  ",arr[i][j]);
//         printf("\n");
//     }
//     return 0;
// }