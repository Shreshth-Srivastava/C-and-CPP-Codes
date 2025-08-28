#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Time Complexity --> O(N) ; Space Complexity --> O(1)

class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int cnt = 0;
        for (int i = 1; i < nums.size() && cnt < 2; ++i) {
            if (nums[i - 1] >= nums[i]) {
                ++cnt;
                if (i > 1 && nums[i - 2] >= nums[i])
                    nums[i] = nums[i - 1];
            }
        }
        return cnt < 2;
    }
};

// class Solution {
// public:
//     bool canBeIncreasing(vector<int>& nums) {
//         int size=nums.size();
//         int removeCount=0, prev=INT_MIN;
//         for(int i=0;i<size-1;i++) {
//             if(nums[i]<nums[i+1])
//                 prev=nums[i];
//             else {
//                 if(removeCount>0)
//                     return false;
//                 removeCount++;
//                 if(nums[i+1]<=prev) {
//                     prev=nums[i];
//                     i++;
//                     if(i+1<size) {
//                         if(nums[i+1]<=prev)
//                             return false;
//                     }
//                 }
//             }
//         }
//         return true;
//     }
// };

// My Solution: Time Complexity --> O(N^2) ; Space Complexity --> O(N)

// class Solution {
// public:
//     bool canBeIncreasing(vector<int>& nums) {
//         if(nums.size()<2) return true;
//         vector<int> temp = nums;
//         for(int i=0;i<nums.size();++i){
//             temp.erase(temp.begin()+i);
//             if(isIncreasing(temp)) return true;
//             temp = nums;
//         }
//         return false;
//     }
// private:
//     bool isIncreasing(vector<int>& nums){
//         if(nums.size() == 1) return true;
//         for(int i=1;i<nums.size();++i){
//             if(nums[i] <= nums[i-1]) return false;
//         }
//         return true;
//     }
// };

int main(){
    Solution sol;
    vector<int> nums = {2,3,1,2};
    // vector<int> nums = {1,2,10,5,7};
    // vector<int> nums = {105,924,32,968};
    sol.canBeIncreasing(nums);
    return 0;
}