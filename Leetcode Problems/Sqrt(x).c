#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// My Solution

int mySqrt(int x) {
    return (int)sqrt((double)x);
}

// Different Approach

// int mySqrt(int x)
// {
//     int low = 0;
//     int high = x;
//     while(low+1 < high) {
//         int mid = (low+high)/2;
//         if(mid*(long long int)mid < x) {
//             low = mid;
//         } else {
//             high = mid;
//         }
//     }
//     return high*(long long int)high == x ? high : low;
// }

int main(void){
    int x = 8;
    printf("%d",mySqrt(x));
    return 0;
}