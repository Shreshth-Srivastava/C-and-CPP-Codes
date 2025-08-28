#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = helper(0, nums.size()-1, nums);
        return root;
    }
private:
    TreeNode* helper(int start, int end, vector<int>& nums){
        int s = start, e = end, root_index = s + (e-s)/2;
        TreeNode* root = new TreeNode(nums[root_index]);
        root->left = helper(start, root_index-1, nums);
        root->right = helper(root_index+1, end, nums);
        return root;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {-10,-3,0,5,9};
    sol.sortedArrayToBST(nums);
    return 0;
}