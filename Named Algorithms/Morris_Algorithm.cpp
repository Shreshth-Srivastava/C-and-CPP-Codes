// Morris Traversal is a tree traversal algorithm that enables in-order or pre-order traversal of a binary tree without using recursion or a stack, achieving O(1) space complexity. It modifies the tree temporarily by establishing "threads" to the predecessor nodes, allowing the traversal to backtrack without additional memory. For in-order traversal, it starts at the root and checks if the left child exists. If not, it visits the node and moves right. If the left child exists, it finds the rightmost node (predecessor) in the left subtree. If the predecessor’s right is null, it creates a temporary thread back to the current node and moves left. If the thread already exists, it removes it, visits the current node, and moves right. This process continues until all nodes are visited. Morris Traversal ensures each node is visited in the correct order and modified at most twice. It is especially useful when memory usage needs to be minimized. The tree is restored to its original structure after the traversal.

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

// Morris Algorithm for Binary Tree inorder traversal

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* temp;
        while(root)
        {
            if(root->left)
            {
                temp=root->left;
                while(temp->right)
                {
                    temp=temp->right;
                }
                temp->right=root;
                temp=root->left;
                root->left=NULL;
                root=temp;
            }
            else
            {
                ans.push_back(root->val);
                root=root->right;
                
            }
        }
        return ans;
    }
};