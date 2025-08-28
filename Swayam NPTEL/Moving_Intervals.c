#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//4th Try 

void Sort(unsigned long int *arr,unsigned long int rows,unsigned int cols){
    for(unsigned long int i = 0;i < (cols*rows)-cols;i += cols){
        for(unsigned long int j = i+cols;j>0;j -= cols){
            if(arr[j]<arr[j-cols]){
                unsigned long int temp;
                for(unsigned int k = 0;k<cols;k++){
                    temp = arr[j+k];
                    arr[j+k] = arr[j-cols+k] ;
                    arr[j-cols+k] = temp;
                }
            }
        }
    }
}

int main(void){
    //Storing input
    unsigned long int C,N;
    unsigned int K;
    scanf("%lu",&C);
    scanf("%lu",&N);
    scanf("%u",&K);
    unsigned long int arr[N][2];
    for(unsigned long int i = 0;i<N;i++){
        for(unsigned int j = 0;j<2;j++){
            scanf("%lu",&(arr[i][j]));
        }
    }
    Sort((unsigned long int *)arr,N,2);
    unsigned long int cakesLeft = C;
    for(unsigned long int i = 0;i<N-1;i++){
        if(arr[i+1][0] < arr[i][1]){
            if(K == 0){
                printf("Bad");
                return 0;
            }
            else{
                if(cakesLeft == 0){
                    printf("Bad");
                    return 0;
                }
                cakesLeft = cakesLeft - (arr[i][1] - arr[i][0] + 1);
                K--;
            }
        }
        else{
            if(cakesLeft == 0){
                printf("Bad");
                return 0;
            }
            cakesLeft = cakesLeft - (arr[i][1] - arr[i][0] + 1);
        }
    }
    unsigned long int finalChild = arr[N-1][1] - arr[N-1][0] + 1;
    if(cakesLeft < finalChild){
        printf("Bad");
        return 0;
    }
    printf("Good");
    return 0;
}

//1st Try

// int main(void){
//     //Storing input
//     int N,C,K,S1,E1,S2,E2;
//     scanf("%d",&N);
//     scanf("%d",&C);
//     scanf("%d",&K);
//     scanf("%d",&S1);
//     scanf("%d",&E1);
//     scanf("%d",&S2);
//     scanf("%d",&E2);
//     //Keeping track of cakes
//     int arr[N];
//     for(int i = 0;i<N;i++) arr[i] = 1;
//     //Child-1
//     for(int i = S1-1;i<E1;i++) arr[i] = 0;
//     //Child-2
//     for(int i = S2-1;i<E2;i++){
//         if(arr[i] == 0){
//             if(K == 0){
//                 printf("Bad");
//                 return 0;
//             }
//             else{
//                 K--;
//                 continue;
//             }
//         }
//     }
//     printf("Good");
//     return 0;
// }

//2nd Try

// int main(void){
//     //Storing input
//     unsigned long int C,N;
//     unsigned int K;
//     scanf("%lu",&C);
//     scanf("%lu",&N);
//     scanf("%u",&K);
//     unsigned long int arr[N][2];
//     for(unsigned long int i = 0;i<N;i++){
//         for(unsigned int j = 0;j<2;j++){
//             scanf("%lu",&(arr[i][j]));
//         }
//     }
//     //Keeping track of cakes
//     bool cakes[C];
//     for(unsigned long int i = 0;i<C;i++) cakes[i] = true;
//     for(unsigned long int i = 0;i<N;i++){
//         for(unsigned long int j = arr[i][0] - 1;j<arr[i][1];j++){
//             //Check for overlap
//             if(cakes[j] == false){
//                 if(K == 0){
//                     printf("Bad");
//                     return 0;
//                 }
//                 else{
//                     K--;
//                     continue;
//                 }
//             }
//             else{
//                 cakes[j] = false;
//             }
//         }
//     }
//     printf("Good");
//     return 0;
// }

//3rd Try

// void MovingIntervals(void){
//     //Storing input
//     int C,N,K;
//     scanf("%d",&C);
//     scanf("%d",&N);
//     scanf("%d",&K);
//     int arr[N][2];
//     for(int i = 0;i<N;i++){
//         for(int j = 0;j<2;j++){
//             scanf("%d",&(arr[i][j]));
//         }
//     }
//     //Keeping track of cakes
//     int cakes[C];
//     for(int i = 0;i<C;i++) cakes[i] = 1;
//     for(int i = 0;i<N;i++){
//         for(int j = arr[i][0] - 1;j<arr[i][1];j++){
//             //Check for overlap
//             if(cakes[j] == 0){
//                 if(K == 0){
//                     printf("Bad");
//                     return;
//                 }
//                 else{
//                     K--;
//                     continue;
//                 }
//             }
//             else{
//                 cakes[j] = 0;
//             }
//         }
//     }
//     printf("Good");
// }

// int main(void){
//     int T;
//     scanf("%d",&T);
//     while(T>0){
//         MovingIntervals();
//         T--;
//     }
//     return 0;
// }