#include<stdio.h>

/*int firstMissingPositive(int* nums, int numsSize);*/

int main(void)
{
    int nums[] = {1,2,0};
    int numsSize = sizeof(nums)/sizeof(int);
    int i=0;
    while(i<numsSize)
    {   
        if(nums[i]>0)
        {
            long int correct = nums[i] - 1;
            if(-1<correct && correct<numsSize)
            {
                if(nums[i] != nums[correct])
                {
                    int a = nums[i];
                    nums[i] = nums[correct];
                    nums[correct] = a;
                }
                else i++;
            }
            else 
            {
                if(correct>=numsSize) i++;
            }
        }
        else i++;
    }
    for(int j=0;j<numsSize;j++)
    {
        if(nums[0] != 1)
        {
            printf("%d",1);
            break;
        }
        else if(nums[j] != j+1) printf("%d\n",j+1);
    }
    return 0;
}