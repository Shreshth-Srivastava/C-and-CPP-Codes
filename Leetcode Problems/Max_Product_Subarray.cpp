#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// NeetCode Solution (Modified Kadane's Algorithm): Time Complexity --> O(N) ; Space Complexity --> O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0], curMax = 1, curMin = 1;
        
        for(const int num: nums){
            int temp = curMax*num;
            curMax = max(max(curMax*num, curMin*num), num);
            curMin = min(min(temp, curMin*num), num);
            res = max(res, curMax);
        }

        return res;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,3,-2,4};
    sol.maxProduct(nums);
    return 0;
}