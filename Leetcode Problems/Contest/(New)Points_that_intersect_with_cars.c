#include <stdio.h>

int numberOfPoints(int** nums, int numsSize, int* numsColSize){
    int a[10000];
    int c=0;
    int t=0;
    int p=0;
    for(int i=0;i<numsSize;i++){
        for(int j=nums[i][0];j<=nums[i][1];j++){
            a[c]=j;
            //printf("%d ",j);
            c++;
        }
    }
    for(int k=0;k<c;k++){
        for(int l=k+1;l<c;l++){
            if(a[k]==a[l]&&p<1){
                //printf("%d ",a[k]);
               t++;
                p++;
            }
            
        }
        p=0;
    }
    //printf(".%d. .%d.",c,t);
    return c-(t);
}

int main(void)
{
    int ans, numsColSize;
    int nums[4][2] = {{1, 3}, {5, 10}, {3, 10}, {5, 9}};
    numsColSize = 2;
    int *a;
    int **b;
    a = (int *)nums;
    b = &a;
    ans = numberOfPoints(b, 4, &numsColSize);
    printf("\n\n%d", ans);
    return 0;
}