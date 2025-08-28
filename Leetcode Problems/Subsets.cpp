#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Neetcode Recursive Solution

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> res;
        dfs(nums, 0, curr, res);
        return res;
    }
private:
    void dfs(vector<int>& nums, int start, vector<int>& curr, vector<vector<int>>& res){
        res.push_back(curr);
        for(int i=start;i<nums.size();i++){
            curr.push_back(nums[i]);
            dfs(nums, i+1, curr, res);
            curr.pop_back();
        }
    }
};

// Iterative Solution

/*class Solution{
public:
    vector<vector<int>> subsets(vector<int>& nums){
        vector<vector<int>> res;
        res.push_back({});
        for(int i=0;i<nums.size();i++){
            int sz = res.size();
            for(int j=0;j<sz;j++){
                vector<int> curr = res[j];
                curr.push_back(nums[i]);
                res.push_back(curr);
            }
        }
        return res;
    }
};*/

// Bit Manipulation Method

/*
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        int num = pow(2, n), i = 0;
        
        while(i<num)
        {
            vector<int> temp;
            for(int j=0; j<n; j++)
            {
                if(i & 1<<j)
                    temp.push_back(nums[j]);
            }
            ans.push_back(temp);
            i++;
        }
        
        return ans;
    }
};
*/

int main(){
    Solution sol;
    vector<int> nums = {1,2,3};
    sol.subsets(nums);
    return 0;
}