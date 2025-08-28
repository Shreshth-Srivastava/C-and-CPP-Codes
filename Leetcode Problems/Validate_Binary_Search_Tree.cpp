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

// 2nd Approach

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        int l_min, l_max = INT_MIN, r_min = INT_MAX, r_max;
        bool left = true, right = true;
        if(root->left != NULL){
            if(root->left->val >= root->val) return false;
            l_min = root->left->val;
            l_max = root->left->val;
            left = dfs(root->left, l_min, l_max);
        }
        if(root->right != NULL){
            if(root->right->val <= root->val) return false;
            r_min = root->right->val;
            r_max = root->right->val;
            right = dfs(root->right, r_min, r_max);
        }
        if(l_max > root->val) return false;
        if(r_min < root->val) return false;
        if(left && right) return true;
        return true;
    }
    bool dfs(TreeNode* root, int& min, int& max){
        bool left = true, right = true;
        if(root->left != NULL){
            if(root->left->val >= root->val) return false;
            if(root->left->val < min) min = root->left->val;
            left = dfs(root->left, min, max);
        }
        if(root->right != NULL){
            if(root->right->val <= root->val) return false;
            if(root->right->val > max) max = root->right->val;
            right = dfs(root->right, min, max);
        }
        if(left && right) return true;
        return false;
    }
};

// 1st Approach

// class Solution {
// public:
//     bool isValidBST(TreeNode* root) {
//         if(root == NULL) return true;
//         if(root->left == NULL && root->right != NULL) return false;
//         if(root->left == NULL && root->right == NULL) return true;
//         if(root->left->val >= root->val || root->right->val <= root->val) return false;
//         bool left = isValidBST(root->left);
//         bool right = isValidBST(root->right);
//         if(!left && !right) return false;
//         return true;
//     }
// };

int main(){
    TreeNode left(-1);
    TreeNode head(0, &left, NULL);
    Solution sol;
    cout<<sol.isValidBST(&head);
    return 0;
}