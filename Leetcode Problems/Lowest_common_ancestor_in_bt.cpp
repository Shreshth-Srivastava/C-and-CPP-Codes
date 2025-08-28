#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* l) : val(x), left(l), right(NULL) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

// Time Complexity --> O(N) ; Space Complexity --> O(N)

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left && right) return root;
        
        return left ? left : right;
    }
};

int main(){
    Solution sol;

    TreeNode second = TreeNode(2);
    TreeNode first = TreeNode(1, &second);

    cout<<(sol.lowestCommonAncestor(&first, &first, &second))->val<<endl;

    return 0;
}