#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// My Solution: Time Complexity --> O(NlogN) ; Space Complexity --> O(logN) for sorting

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int& k) {
        int n = nums.size();
        if (n % 3 != 0) return {};
        
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        for(int i=0;i<n-2;i+=3){
            if(nums[i+2]-nums[i]>k){
                return {};
            }

            res.push_back({nums[i], nums[i+1], nums[i+2]});
        }

        return res;
    }
};

int main(){
    Solution sol;

    // vector<int> nums = {1,3,4,2,3,5};
    // int k = 2;

    // vector<int> nums = {1,3,4,8,7,9,3,5,1};
    // int k = 2;

    vector<int> nums = {2,4,2,2,5,2};
    int k = 2;

    sol.divideArray(nums, k);

    return 0;
}