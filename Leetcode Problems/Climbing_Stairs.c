/*

Test Cases :-

n = 5{
    all 1's [1 way]
        1+1+1+1+1
    one 2 invloved [4 ways]
        2+1+1+1
        1+2+1+1
        1+1+2+1
        1+1+1+2
    two 2's [3 ways]
        2+2+1
        1+2+2
        2+1+2
}

n = 6{
    all 1's [1 way]
    one 2 [5 ways]
        2+1+1+1+1
        1+2+1+1+1
        1+1+2+1+1
        1+1+1+2+1
        1+1+1+1+2
    two 2's [6 ways]
        2+2+1+1
        2+1+2+1
        2+1+1+2
        1+2+2+1
        1+2+1+2
        1+1+2+2
    three 2's [1 way]
        2+2+2
}

Approach-1 : Using fibonacci series through recursion --> TLE
Solution : Generating fibonacci series using for loop

*/

#include<stdio.h>
#include<stdlib.h>

// fibonacci series using recursion

// int climbStairs(int n) {
//     if(n == 1) return 1;
//     if(n == 2) return 2;
//     if(n > 2){
//         int result = climbStairs(n-1) + climbStairs(n-2);
//         return result;
//     }
//     return 0;
// }

// Generating fibonacci series using for loop

int climbStairs(int n) {
    // Simply Generate fibonacci series
    if( n<=1 ) return 1;
    int a = 1, b = 1, result = 0;
    for(int i = 1;i<n;i++){
        result = a+b;
        a = b;
        b = result;
    }
    return result;
}

int main(void){
    printf("%d",climbStairs(3));
    return 0;
}