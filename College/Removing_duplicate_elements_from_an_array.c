#include <stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b){
    return (*(int *)a - *(int *)b);
}

int removeDuplicates(int *nums, int numsSize)
{
    qsort(nums,numsSize,sizeof(int),cmp);
    int j = 1;
    for (int i = 0; i < numsSize - 1; i++)
    {
        if (nums[i] != nums[i + 1])
        {
            nums[j] = nums[i + 1];
            j++;
        }
    }
    return j;
}

int main(void)
{
    int arr[10] = {5,1,5,2,3,2,4,3,4,10};
    int j = removeDuplicates(arr, 10);
    for (int i = 0; i < j; i++)
        printf("\n%d", arr[i]);
    return 0;
}