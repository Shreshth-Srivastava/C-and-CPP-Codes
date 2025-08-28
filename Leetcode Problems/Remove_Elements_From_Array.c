#include <stdio.h>

void swap(int array[], int a, int b)
{
    int temp;
    temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

int removeElement(int *nums, int numsSize, int val)
{
    int i = 0;
    while (i < numsSize)
    {
        if (nums[i] == val)
        {
            swap(nums, i, numsSize - 1);
            numsSize--;
        }
        else
            i++;
    }
    return numsSize;
}