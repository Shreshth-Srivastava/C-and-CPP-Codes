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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }
private:
    void helper(TreeNode* root, vector<int>& arr){
        if(root == NULL) return;
        if(root->left != NULL) helper(root->left, arr);
        if(root->right != NULL) helper(root->right, arr);
        arr.push_back(root->val);
    }
};

int main(){
    TreeNode second = TreeNode(3);
    TreeNode first = TreeNode(2, &second, NULL);
    TreeNode root = TreeNode(1, NULL, &first);
    Solution sol;
    vector<int> arr = sol.postorderTraversal(&root);
    for(auto it: arr){
        cout<<it<<endl;
    }
    return 0;
}