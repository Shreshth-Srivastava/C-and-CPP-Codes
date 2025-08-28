#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* 
Note: Q1/Q2: Use a sliding window to determine the places at which there is a subarray with consecutive increasing integers. Keep track of a left pointer, initialized to 0. Go through the array, and when we encounter a new number, if it is not equal to the previous number + 1, set our left pointer to the current index. If the distance between our current pointer and the left pointer is k, set the answer array at the left pointer equal to nums[i], then increment the left pointer. Once we're done the main loop, go through the answer array and set all remaining values to -1.
Q3/Q4: Note that we only need to keep track of the 3 largest elements of each row. Then, we can run a simple O(n^3) algorithm that goes through all triplets of rows and brute forces all combinations of the 3 largest elements in each row. This passes Q3 but has a massive constant factor of 27, so it may TLE on Q4. However if you simply check to see if the maximum value of each selected row is greater than the current best answer, you can still AC Q4 (constant optimization letsgooooo!!!)
*/
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
       int n = nums.size();
        vector<int>dp(n+1);
        dp[0] = 1;
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1] == 1){
                dp[i] = dp[i-1]+1;
                
            }
            else dp[i] = 1;
        }
        vector<int> ans;
        for(int i=k-1;i<n;i++){
            if(dp[i]>=k){
                ans.push_back(nums[i]);
            }
            else ans.push_back(-1);
        }
        return ans;

    }
};

int main(){
    Solution sol;
    vector<int> arr = {1,2,3,4,3,2,5};
    sol.resultsArray(arr, 3);
    return 0;
}