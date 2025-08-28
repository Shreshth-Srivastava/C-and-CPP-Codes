#include <stdio.h>

int numberOfPoints(int **nums, int numsSize, int *numsColSize)
{
    int arr[100];
    int reference[100];
    int check[100];
    int counter = 0;
    int second_counter = 0;
    int a = *numsColSize;
    int *b;
    b = *nums;
    int c = 0;
    int d = -1;
    int min = 0;
    int max = 0;
    int ans = 0;
    for (int i = 0; i < numsSize; i++)
    {
        int j = i * 2;
        for (int k = 0; k < a; k++)
        {
            arr[j + k] = *(b + j + k); //use nums[i][k] for leetcode
        }
        c = arr[j];
        d = arr[j + 1];
        if (min == 0 && max == 0)
        {
            for (int m = c; m <= d; m++)
            {
                reference[counter] = m;
                counter++;
            }
            min = c;
            max = d;
            while (c <= d)
            {
                ans++;
                c++;
                printf("\n%d-", ans);
            }
            continue;
        }

        if (c > max)
        {
            for (int m = c; m <= d; m++)
            {
                reference[counter] = m;
                counter++;
            }
            while (c <= d)
            {
                ans++;
                c++;
                printf("\n%d--", ans);
            }
            max = d;
        }

        if (d > max)
        {
            for (int m = max; m <= d; m++)
            {
                reference[counter] = m;
                counter++;
            }
            for (int k = max; k < d; k++)
                ans++;
            printf("\n%d---", ans);
            max = d;
        }

        if (c < min)
        {
            if(d < min){
                for (int m = c; m < d; m++)
            {
                reference[counter] = m;
                counter++;
            }
                for (int l = c; l < d; l++)
                ans++;
                printf("\n%d----", ans);
                min = c;
            }
            else{
            for (int m = c; m < min; m++)
            {
                reference[counter] = m;
                counter++;
            }
            for (int l = c; l < min; l++)
                ans++;
            printf("\n%d----", ans);
            min = c;
            }
        }

        if (d <= max)
        {
            for (int n = c; n <= d; n++)
            {
                check[second_counter] = n;
                second_counter++;
            }
            for (int o = 0; o < second_counter; o++)
            {
                int flag = 1;
                for (int p = 0; p < counter; p++)
                {
                    if (reference[p] == check[o]){
                        flag = 0;
                        break;
                    }
                }
                if (flag != 0)
                    ans++;
                printf("\n%d-----", ans);
            }
            for (int m = c; m <= d; m++)
            {
                reference[counter] = m;
                counter++;
            }
        }
    }
    return ans;
}

    int main(void)
    {
        int ans, numsColSize;
        int nums[4][2] = {{1,3}, {5,10}, {3,10},{5,9}};
        numsColSize = 2;
        int *a;
        int **b;
        a = (int *)nums;
        b = &a;
        ans = numberOfPoints(b, 4, &numsColSize);
        printf("\n\n%d", ans);
        return 0;
    }