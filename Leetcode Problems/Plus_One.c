/*
Given:-
1. 1<= input array size <=100
2. digits[] does not contain any leading 0's

Approach 1:-
1. Use a loop to traverse backwards as you increment the value by one (eg. 999)
2. If digits[0] + 1 > 10, flag = true else false
3. If flag == true, increment the value of N [N = sizeof(digits)/sizeof(digits[0])], lets call it N'
4.1 malloc a new array, say arr, with size N' and arr[0] = 1. Additionally copy the rest of the elements from digits to arr
5.1 return arr
4.2 If flag == false, return digits
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int *plusOne(int *digits, int digitsSize, int *returnSize)
{
    bool flag = false;
    for (int i = digitsSize - 1; i >= 0; i--)
    {
        if (digits[i] + 1 == 10)
        {
            if (i == 0)
            {
                flag = true;
            }
            digits[i] = 0;
        }
        else
        {
            digits[i]++;
            break;
        }
    }
    if (flag == true)
    {
        int N = digitsSize + 1;
        int *arr = (int *)malloc(sizeof(int) * N);
        arr[0] = 1;
        for(int j = 1;j<N;j++){
            arr[j] = digits[j-1];
        }
        *returnSize = N;
        return arr;
    }
    *returnSize = digitsSize;
    return digits;
}

int main(void)
{
    int digits[3] = {9,9,9};
    int *returnSize;
    int *arr = plusOne(digits, 3, returnSize);
    printf("\n");
    for (int i = 0; i < *returnSize; i++)
    {
        printf("%d", arr[i]);
    }
    return 0;
}