#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// NeetCode Top-Down Approach: Time Complexity --> O(n*m) ; Space Complexity --> O(n*m) where n is the size of arr nums and m is the sum of all elements in the arr

class Solution {
    vector<vector<int>> dp;
    int totalSum;

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        totalSum = accumulate(nums.begin(), nums.end(), 0);
        dp = vector<vector<int>>(nums.size(), vector<int>(2 * totalSum + 1, INT_MIN));
        return backtrack(0, 0, nums, target);
    }
    
    int backtrack(int i, int total, vector<int>& nums, int target) {
        if (i == nums.size()) {
            return total == target;
        }
        if (dp[i][total + totalSum] != INT_MIN) {
            return dp[i][total + totalSum];
        }
        dp[i][total + totalSum] = backtrack(i + 1, total + nums[i], nums, target) + 
                                  backtrack(i + 1, total - nums[i], nums, target);
        return dp[i][total + totalSum];
    }
};

// My Top-Down Approach

// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         return helper(0, 0, nums, target);
//     }

// private:
//     unordered_map<string, int> dp;

//     int helper(int i, int cur_sum, vector<int>& nums, int target){
//         if(i == nums.size()){
//             return cur_sum == target;
//         }

//         string key = to_string(i) + "-" + to_string(cur_sum);

//         if(dp.find(key) != dp.end()) return dp[key];

        
//         dp[key] = helper(i+1, cur_sum+nums[i], nums, target) + helper(i+1, cur_sum-nums[i], nums, target);
//         return dp[key];
//     }
// };

// Recursion

// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         return helper(0, 0, nums, target);
//     }

// private:
//     int helper(int i, int cur_sum, vector<int>& nums, int target){
//         if(i == nums.size()){
//             return cur_sum == target;
//         }
        
//         return helper(i+1, cur_sum+nums[i], nums, target) + helper(i+1, cur_sum-nums[i], nums, target);
//     }
// };

int main(){
    Solution sol;
    vector<int> nums = {1,1,1,1,1};
    sol.findTargetSumWays(nums, 3);
    return 0;
}