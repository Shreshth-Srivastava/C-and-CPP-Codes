//Improved Solution but neglegible performance improvement

// int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
//     int count[1001] = {0};
//     int n = (nums1Size<nums2Size)?nums1Size:nums2Size;
//     int *arr = (int *)malloc(sizeof(int)*n);
//     for(int i = 0;i<nums1Size;i++){
//         count[nums1[i]]++;
//     }
//     *returnSize = 0;
//     for(int k = 0;k < nums2Size;k++){
//         if(count[nums2[k]] != 0){
//             arr[*returnSize] = nums2[k];
//             count[nums2[k]]--;
//             (*returnSize)++;
//         }
//     }
//     return arr;
// }

//My Solution

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int count1[1001] = {0},count2[1001] = {0},ptr = 0;
    int n = (nums1Size<nums2Size)?nums1Size:nums2Size;
    int *arr = (int *)malloc(sizeof(int)*n);
    for(int i = 0;i<nums1Size;i++){
        count1[nums1[i]]++;
    }
    for(int j = 0;j<nums2Size;j++){
        count2[nums2[j]]++;
    }
    *returnSize = 0;
    for(int k = 0;k < nums1Size;k++){
        if(count1[nums1[k]] > 0 && count2[nums1[k]] > 0){
            arr[ptr++] = nums1[k];
            count1[nums1[k]]--;
            count2[nums1[k]]--;
            *returnSize = *returnSize+1;
        }
    }
    return arr;
}