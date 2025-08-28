#include <stdio.h>
#include <stdlib.h>

int *sortArrayByParity(int *nums, int numsSize, int *returnSize)
{
    *returnSize = numsSize;
    int a = 0, b = 0;
    int *arr;
    arr = (int *)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++)
    {
        if (!(nums[i] & 1))
        {
            arr[a++] = nums[i];
        }
        else
        {
            arr[numsSize - 1 - b] = nums[i];
            b++;
        }
    }
    return arr;
}

int main(void)
{
    int nums[4] = {3, 1, 2, 4};
    int *a;
    int *b = 4;
    a = sortArrayByParity(nums, 4, &b);
    for (int i = 0; i < 4; i++)
        printf("\n%d", a[i]);
    return 0;
}