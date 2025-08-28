#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};


// My Solution
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int left = dfs(root->left);
        int right = dfs(root->right);
        if((left > right + 1) || (right > left + 1)) return false;
        if(!isBalanced(root->left)) return false;
        if(!isBalanced(root->right)) return false;
        return true;
    }
    int dfs(TreeNode* root){
        if(root == NULL) return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        if((l == 0) ^ (r == 0)) return ((l>r)?l:r)+1;
        else{
            if(l > r) return l+1;
            else return r+1;
        }
    }
};

// Other Approach
// class Solution {
// public:
//     bool isBalanced(TreeNode* root) {
//         int height = 0;
//         return dfs(root, height);
//     }
// private:
//     bool dfs(TreeNode* root, int& height) {
//         if (root == NULL) {
//             height = -1;
//             return true;
//         }
        
//         int left = 0;
//         int right = 0;
        
//         if (!dfs(root->left, left) || !dfs(root->right, right)) {
//             return false;
//         }
//         if (abs(left - right) > 1) {
//             return false;
//         }
        
//         height = 1 + max(left, right);
//         return true;
//     }
// };

int main(){
    Solution sol;

    struct TreeNode* head = (struct TreeNode*)malloc(sizeof(struct TreeNode*));
    struct TreeNode* first = (struct TreeNode*)malloc(sizeof(struct TreeNode*));
    struct TreeNode* second = (struct TreeNode*)malloc(sizeof(struct TreeNode*));
    
    head->left = NULL;
    head->right = first;
    head->val = 1;

    first->left = NULL;
    first->right = second;
    first->val = 2;

    second->left = NULL;
    second->right = NULL;
    second->val = 3;
    cout<<"Output: "<<sol.isBalanced(head);
    return 0;
}