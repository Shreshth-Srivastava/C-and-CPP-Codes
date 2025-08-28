#include <stdio.h>

int removeDuplicates(int *nums, int numsSize)
{
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
    int a[3] = {1, 1, 2};
    int j = removeDuplicates(a, 3);
    for (int i = 0; i < j; i++)
        printf("\n%d", a[i]);
    return 0;
}