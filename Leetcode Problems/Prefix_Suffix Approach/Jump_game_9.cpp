#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Time Complexity --> O(N) ; Space Complexity --> O(N)

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        const int n = nums.size();
        vector<int> prefix(n), suffix(n), res(n);

        prefix[0] = nums[0], suffix[n-1] = nums[n-1];

        for(int i=1;i<n;++i){
            prefix[i] = max(nums[i], prefix[i-1]);
        }

        for(int i=n-2;i>=0;--i){
            suffix[i] = min(nums[i], suffix[i+1]);
        }

        res[n-1] = prefix[n-1];
        for(int i=n-2;i>=0;--i){
            res[i] = prefix[i];
            if(prefix[i] > suffix[i+1])
                res[i] = res[i+1];
        }

        return res;
    }
};

int main(){
    Solution sol;

    // vector<int> nums = {2,1,3};
    vector<int> nums = {2,3,1};

    sol.maxValue(nums);

    return 0;
}