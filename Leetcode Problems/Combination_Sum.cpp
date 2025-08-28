#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// My Solution

class Solution {
public:
    vector<int> curr;
    vector<vector<int>> res;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        helper(candidates, 0, 0, target);
        return res;
    }
private:
    void helper(vector<int>& candidates, int start, int sum, int target){
        if(sum == target) res.push_back(curr);
        else if(sum < target){
            for(int i=start;i<candidates.size();i++){
                curr.push_back(candidates[i]);
                helper(candidates, i, (sum + candidates[i]), target);
                curr.pop_back();
            }
        }
    }
};

// A little better solution :: NeetCode
/*
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> res;
        helper(candidates, target, 0, curr, res);
        return res;
    }
private:
    void helper(vector<int>& cands, int target, int i, vector<int>& curr,  vector<vector<int>>& res) {
        if (i >= cands.size() || target < 0)
            return;

        if (target == 0) {
            res.push_back(curr);
            return;
        }

        curr.push_back(cands[i]);
        
        helper(cands, target - cands[i], i, curr, res);

        curr.pop_back();

        helper(cands, target, i + 1, curr, res);
    }
};
*/

int main(){
    Solution sol;
    vector<int> nums = {2,3,6,7};
    sol.combinationSum(nums, 7);
    return 0;
}