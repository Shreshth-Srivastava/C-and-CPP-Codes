#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Greedy (BFS Type): Time Complexty --> O(N) ; Space Complexity --> O(1)
class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0, l = 0, r = 0;

        while (r < nums.size() - 1) {
            int farthest = 0;
            for (int i = l; i <= r; i++) {
                farthest = max(farthest, i + nums[i]);
            }
            l = r + 1;
            r = farthest;
            res++;
        }
        return res;
    }
};

// DP Bottom-Up Approach
// class Solution {
// public:    
//     int jump(vector<int>& nums) {
//         int n = nums.size() - 1;
//         vector<int> dp(n+1, 10000);
//         dp[n] = 0;
        
//         for(int i=n-1;i>=0;i--){
//             for(int j=1;j<=nums[i];j++){
//                 if(i+j <= n){
//                     dp[i] = min(dp[i], dp[i+j]+1);
//                 }
//             }
//         }

//         return dp[0];
//     }
// };

// DP Top-Down Approach

// class Solution {
// public:
//     int minSteps = INT_MAX;
    
//     int jump(vector<int>& nums) {
//         int n = nums.size() - 1;
//         vector<int> dp(n+1, -1);
//         dp[n] = 0;
//         return helper(0, nums, n, 0, dp);
//     }

// private:
//     int helper(int index, vector<int>& nums, int end, int curStep, vector<int>& dp){
//         if(index >= end) return curStep;
//         if(dp[index] != -1) return dp[index]+curStep;
//         for(int i=1;i<=nums[index];i++){
//             minSteps = min(minSteps, helper(index+i, nums, end, curStep+1, dp));
//         }
//         dp[index] = minSteps - curStep;
//         return minSteps;
//     }
// };

// Recursion

// class Solution {
// public:
//     int minSteps = INT_MAX;
    
//     int jump(vector<int>& nums) {
//         int n = nums.size() - 1;
//         return helper(0, nums, n, 0);
//     }

// private:
//     int helper(int index, vector<int>& nums, int end, int curStep){
//         if(index >= end) return curStep;
//         for(int i=1;i<=nums[index];i++){
//             minSteps = min(minSteps, helper(index+i, nums, end, curStep+1));
//         }
//         return minSteps;
//     }
// };

int main(){
    Solution sol;
    // vector<int> nums = {2,3,1,1,4};
    // vector<int> nums = {1,2,1,1,1};
    vector<int> nums = {2,3,0,1,4};
    cout<<sol.jump(nums);
    return 0;
}