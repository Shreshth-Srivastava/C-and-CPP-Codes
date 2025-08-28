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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        return helper(preorder, inorder, index, 0, inorder.size() - 1);
    }
private:
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& index, int i, int j){
        if(i > j) return NULL;

        TreeNode* root = new TreeNode(preorder[index]);

        int split = 0;
        for(int k = 0;k<inorder.size();k++){
            if(preorder[index] == inorder[k]){
                split = k;
                break;
            }
        }
        index++;

        root->left = helper(preorder, inorder, index, i, split-1);
        root->right = helper(preorder, inorder, index, split+1, j);
        
        return root;
    }
};

int main(){
    Solution sol;
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    return 0;
}

/*
Why the error occurs:
In the recursive function helper, the index variable is passed by value (as it is a regular integer). However, after the recursive call to root->left, the index value used for the right subtree is not updated, causing both root->left and root->right to use the same (and incremented) index. This leads to multiple accesses beyond the end of the preorder array, resulting in the heap-buffer-overflow.

Solution:
To fix this, you need to properly manage the index variable, ensuring that it's correctly updated across recursive calls. One common way to do this is to pass index by reference, so its value is consistently updated across both left and right subtree recursions.
*/