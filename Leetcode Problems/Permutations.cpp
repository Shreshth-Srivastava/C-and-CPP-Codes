#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Neetcode Solution

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        dfs(nums, 0, result);
        return result;
    }
private:
    void dfs(vector<int>& nums, int start, vector<vector<int>>& result) {
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            swap(nums[i], nums[start]);
            dfs(nums, start + 1, result);
            swap(nums[i], nums[start]);
        }
    }
};

// My Solution , Good Time response but takes a lot of space

/*class Solution {
public:
    vector<int> curr;
    vector<vector<int>> res;
    unordered_set<int> s;

    vector<vector<int>> permute(vector<int>& nums) {
        helper(0, nums.size(), nums);
        return res;
    }
private:
    void helper(int start, int end, vector<int>& nums){
        if(start == end){
            res.push_back(curr);
            return;
        }
        for(int i=0;i<end;i++){
            if(!s.count(nums[i])){
                curr.push_back(nums[i]);
                s.insert(nums[i]);
                helper(start+1, end, nums);
                curr.pop_back();
                s.erase(nums[i]);
            }
        }
    }
};*/

int main(){
    Solution sol;
    vector<int> nums = {1,2,3};
    sol.permute(nums);
    return 0;
}