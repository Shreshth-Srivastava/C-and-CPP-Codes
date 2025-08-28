#include<stdio.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    if(m == 0){
        for(int i=0;i<n;i++){
            nums1[i] = nums2[i];
        }
    }
    else{
        if(n == 0) return;
        else{
            int ptr = nums1Size - 1;
            m--;n--;
            for(int i=nums1Size;i>0;i--){
                if(m >= 0 && n >= 0){
                    if(nums1[m] > nums2[n]){
                        nums1[ptr] = nums1[m];
                        m--;ptr--;
                    }
                    else{
                        nums1[ptr] = nums2[n];
                        n--;ptr--;
                    }
                }
            }
            if(m < 0){
                for(int j = n;j>=0;j--){
                    nums1[ptr] = nums2[j];
                    ptr--;
                }
            }
            if(n < 0){
                for(int j = m;j>=0;j--){
                    nums1[ptr] = nums1[j];
                    ptr--;
                }
            }
        }
    }
}

int main(void){
    int nums1[6] = {1,2,3,0,0,0}, nums2[3] = {2,5,6}, m = 3, n = 3;
    merge(nums1,6,m,nums2,3,n);
    for(int i=0;i<m+n;i++){
        printf("%d ",nums1[i]);
    }
    return 0;
}