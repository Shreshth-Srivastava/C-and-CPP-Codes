#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// My Solution: Time Complexity --> O(2^N) ; Space Complexity --> O(2^N)

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        unordered_map<int, int> m;
        int maxElem = INT_MIN, n = nums.size();

        
        dfs(0, 0, m, maxElem, nums, n);

        return m[maxElem];
    }
private:
    void dfs(int idx, int curr, unordered_map<int, int>& m, int& maxElem ,vector<int>& nums, int n){
        if(idx >= n){
            m[curr]++;
            maxElem = max(maxElem, curr);
            return;
        }

        int temp = nums[idx] | curr;

        // take
        dfs(idx+1, temp, m, maxElem, nums, n);
        
        // not take
        dfs(idx+1, curr, m, maxElem, nums, n);
    }
};

int main(){
    Solution sol;

    vector<int> nums = {3,1};
    cout<<sol.countMaxOrSubsets(nums);

    return 0;
}