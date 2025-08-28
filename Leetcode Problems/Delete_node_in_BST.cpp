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

// Time Complexity --> O(logN) ; Space Complexity --> O(1)

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if(root->val > key) root->left = deleteNode(root->left, key);
        else if(root->val < key) root->right = deleteNode(root->right, key);
        else {
            if(!root->right) return root->left;
            if(!root->left) return root->right;
            TreeNode* tmp = root->right;
            while(tmp->left) tmp = tmp->left;
            root->val = tmp->val;
            root->right = deleteNode(root->right, tmp->val);
        }
        return root;
    }
};

int main(){
    Solution sol;

    TreeNode third = TreeNode(2);
    TreeNode fourth = TreeNode(4);
    TreeNode fifth = TreeNode(7);

    TreeNode second = TreeNode(6, nullptr, &fifth);
    TreeNode first = TreeNode(3, &third, &fourth);

    TreeNode root = TreeNode(5, &first, &second);

    sol.deleteNode(&root, 3);

    return 0;
}