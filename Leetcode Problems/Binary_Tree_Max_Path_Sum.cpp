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

// My Solution: Time Complexity --> O(N) ; Space Complexity --> O(N)

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        dfs(root, res);
        return res;
    }
    
private:
    int dfs(TreeNode* node, int& res){
        if(node == nullptr) return 0;

        int left = dfs(node->left, res);
        int right = dfs(node->right, res);

        res = max(res, node->val + left + right);

        left += node->val;
        right += node->val;
        return max(left, max(right, 0));
    }
};

int main(){
    Solution sol;

    // TreeNode third = TreeNode(3);
    // TreeNode second = TreeNode(2);
    // TreeNode root = TreeNode(1, &second, &third);
    // sol.maxPathSum(&root);

    // TreeNode fifth = TreeNode(7);
    // TreeNode fourth = TreeNode(15);
    // TreeNode third = TreeNode(20, &fourth, &fifth);
    // TreeNode second = TreeNode(9);
    // TreeNode root = TreeNode(-10, &second, &third);
    // sol.maxPathSum(&root);

    TreeNode fifth = TreeNode(-5);
    TreeNode fourth = TreeNode(-4);
    TreeNode third = TreeNode(3, &fourth, &fifth);
    TreeNode second = TreeNode(2);
    TreeNode root = TreeNode(1, &second, &third);
    cout<<sol.maxPathSum(&root);

    return 0;
}