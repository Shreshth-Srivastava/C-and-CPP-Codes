#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Memoization

class Solution{
public:
    int rob(vector<int>& nums){
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        return max(helper(0, n-2, dp1, nums), helper(1, n-1, dp2, nums));
    }
private:
    int helper(int start, int end, vector<int>& dp, vector<int>& nums){
        if(start > end) return 0;

        if(dp[start] != -1) return dp[start];

        if(start == end){
            dp[end] = nums[end];
            return nums[end];
        }

        if(end - start == 1){
            return dp[start] = max(nums[start], nums[end]);
        }

        dp[start] = nums[start] + max(helper(start+2, end, dp, nums), helper(start+3, end, dp, nums));
        return max(dp[start], helper(start+1, end, dp, nums));
    }
};

// Tabulation

/*class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        vector<int> dp(n, 0);
        for(int i = 0;i<n;i++) dp[i] = nums[i];
        int res1, res2;

        for(int i = n-4;i>=0;i--){
            if(i == n-4) dp[i] += dp[i+2];
            else dp[i] += max(dp[i+2], dp[i+3]);
        }
        res1 = max(dp[0], dp[1]);

        for(int i = n-3;i>=1;i--){
            if(i == n-3) nums[i] += nums[i+2];
            else nums[i] += max(nums[i+2], nums[i+3]);
        }
        res2 = max(nums[1], nums[2]);
        
        return max(res1, res2);
    }
};*/

int main(){
    Solution sol;
    vector<int> nums = {1,2,3,4,5,1,2,3,4,5};
    cout<<sol.rob(nums);
    return 0;
}