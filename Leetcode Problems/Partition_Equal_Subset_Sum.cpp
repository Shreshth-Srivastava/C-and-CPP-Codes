#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Time Complexity --> O(N*Target) where Target = Sum/2 ; Space Complexity --> O(Sum)

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0, count = 0;
        for(const auto& num: nums) sum += num;
        if(sum&1) return false;
        sum /= 2;

        vector<bool> dp(sum+1, false);
        dp[0] = true;
        for(int num: nums){
            for(int j=sum;j>=num;j--){
                dp[j] = dp[j] || dp[j-num];
            }
        }

        return dp[sum];
    }
};

// My Solution (Incomplete)

// class Solution {
// public:
//     bool canPartition(vector<int>& nums) {
//         int n = nums.size(), sum = 0, count = 0;
//         for(const auto& num: nums) sum += num;
//         if(sum&1) return false;

//         sum /= 2;
//         vector<int> dp(n, sum);

//         for(int i=n-1;i>=0;--i){
//             for(int j=i+1;j<n;j++){
//                 if(dp[i]-nums[j] >= 0){
//                     dp[i] = min(dp[i], dp[i]-nums[j]);
//                     count++;
//                 }
//             }
//             // sum = min(dp[i], sum);
//             dp[i] = min(dp[i], sum-nums[i]);
//         }

//         if(sum == 0 && count != n-1) return true;
//         return false;
//     }
// };

int main(){
    Solution sol;
    vector<int> nums = {1,2,5};
    // vector<int> nums = {3,3,6,8,16,16,16,18,20};
    sol.canPartition(nums);
    return 0;
}