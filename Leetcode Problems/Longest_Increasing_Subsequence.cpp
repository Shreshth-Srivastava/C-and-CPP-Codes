#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// NeetCode Solution: Time Complexity --> O(N^2) ; Space Complexity --> O(N)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), maxElem = INT_MIN;
        vector<int> dp(n, 1);
        
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(nums[i] < nums[j]){
                    dp[i] = max(dp[i],1 + dp[j]);
                }
            }
            maxElem = max(maxElem, dp[i]);
        }

        return maxElem;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {10,9,2,5,3,7,101,18};
    sol.lengthOfLIS(nums);
    return 0;
}