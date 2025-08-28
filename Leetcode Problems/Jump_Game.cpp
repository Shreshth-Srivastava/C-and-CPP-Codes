#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Greedy: Time Complexity --> O(N) ; Space Complexity --> O(1)

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size() - 1;

        for (int i = nums.size() - 2; i >= 0; i--) {
            if (i + nums[i] >= goal) {
                goal = i;
            }
        }

        return goal == 0;
    }
};

// DP Bottom-Up Approach

// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         int n = nums.size();
//         vector<bool> dp(n, false);
//         dp[n-1] = true;

//         for(int i=n-2;i>=0;i--){
//             for(int j=1;j<=nums[i];j++){
//                 if( (i+j < n) && (dp[i+j] == true)){
//                     dp[i] = dp[i+j];
//                     break;
//                 }
//             }
//         }

//         return dp[0];
//     }
// };

// DP Top-Down Approach

// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n, -1);
//         dp[n-1] = 1;
//         return helper(0, nums, n-1, dp);
//     }

// private:
//     bool helper(int index, vector<int>& nums, int end, vector<int>& dp){
//         if(index >= end) return true;
//         if(dp[index] != -1) return dp[index];
//         for(int i=1;i<=nums[index];i++){
//             if(helper(index+i, nums, end, dp)){
//                 dp[index] = 1;
//                 return true;
//             }
//         }
//         dp[index] = false;
//         return false;
//     }
// };

// Recursion

// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         int n = nums.size();
//         return helper(0, nums, n-1);
//     }

// private:
//     bool helper(int index, vector<int>& nums, int end){
//         if(index >= end) return true;
//         for(int i=1;i<=nums[index];i++){
//             if(helper(index+i, nums, end)) return true;
//         }
//         return false;
//     }
// };

int main(){
    Solution sol;
    vector<int> nums = {2,3,1,1,4};
    cout<<sol.canJump(nums);
    return 0;
}