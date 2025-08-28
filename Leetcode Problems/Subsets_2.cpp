#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        helper(0, nums);
        return res;
    }
private:
    vector<int> curr;
    void helper(int start, vector<int>& nums){
        res.push_back(curr);
        for(int i=start;i<nums.size();i++){
            if(i>start && nums[i] == nums[i-1]) continue;
            curr.push_back(nums[i]);
            helper(i+1, nums);
            curr.pop_back();
        }
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,2,2};
    sol.subsetsWithDup(nums);
    return 0;
}