#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Bit Manipulation: Time Complexity --> O(N) ; Space Complexity --> O(1)
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int i = n-1;
        for(int j=nums.size()-1;j>=n;j--){
            nums[j] <<= 10;
            nums[j] |= nums[i];
            i--;
        }

        i = 0;
        for(int j=n;j<nums.size();j++){
            nums[i] = nums[j] & 1023;
            nums[i+1] = nums[j] >> 10;
            i += 2;
        }

        return nums;
    }
};

// My Solution: Time Complexity --> O(N) ; Space Complexity --> O(N)

// class Solution {
// public:
//     vector<int> shuffle(vector<int>& nums, int n) {
//         vector<int> res(nums.size(), 0);
//         int ptr1=0, ptr2=n;
//         for(int i=0;i<res.size();i++){
//             if(i&1){
//                 res[i] = nums[ptr2];
//                 ptr2++;
//             }
//             else{
//                 res[i] = nums[ptr1];
//                 ptr1++;
//             }
//         }
//         return res;
//     }
// };

int main(){
    Solution sol;
    vector<int> nums = {2,5,1,3,4,7};
    sol.shuffle(nums, 3);
    return 0;
}