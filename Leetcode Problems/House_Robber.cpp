#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// My Solution, Tabulation approach

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        for(int i = n-3;i>=0;i--){
            if(i == n-3) nums[i] += nums[i+2];
            else nums[i] += max(nums[i+2], nums[i+3]);
        }
        return max(nums[0], nums[1]);
    }
};

// My Solution, DP Solution, Memoization

/*class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return maxAmt(0, dp, nums);
    }
private:
    int maxAmt(int start, vector<int>& dp, vector<int>& nums){
        if(start == nums.size()-1) return dp[start] = nums[start];
        if(start >= nums.size()) return 0;
        if(dp[start] != -1) return dp[start];
        int amt = nums[start];
        if(start+2 < nums.size()){
            for(int i = start+2; i<nums.size();i++){
                amt = nums[start];
                amt += max(maxAmt(i, dp, nums), maxAmt(i+1, dp, nums));
                dp[start] = max(dp[start], amt);
            }
        }
        else{
            amt = max(nums[start], nums[start+1]);
            dp[start] = max(dp[start], amt);
        }
        return max(dp[start], maxAmt(start+1, dp, nums));
    }
};*/

// Another Approach

/*class Solution {
public: 
    int rob(vector<int>& nums) {
        int n = nums.size(), pre = 0, cur = 0;
        for (int i = 0; i < n; i++) {
            int temp = max(pre + nums[i], cur);
            pre = cur;
            cur = temp;
        }
        return cur;
    }
};*/

int main(){
    Solution sol;
    vector<int> nums = {4,1,2,7,5,3,1};
    cout<<sol.rob(nums);
    return 0;
}