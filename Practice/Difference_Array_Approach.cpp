#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
// ---------------------------------------------------------------------------
//      Difference Array Approach
        vector<int> diff(n+2, 0);
        for(const auto query: queries){
            diff[query[0]] += 1;
            diff[query[1]+1] -= 1;
        }
        for(int i=1;i<n+2;i++){
            diff[i] += diff[i-1];
        }
// ---------------------------------------------------------------------------
        for(int i=0;i<n;i++){
            if(nums[i] > diff[i]) return false;
        }

        return true;
    }
};