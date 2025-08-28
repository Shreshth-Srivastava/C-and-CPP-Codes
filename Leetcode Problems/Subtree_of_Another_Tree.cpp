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

// My Solution
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if((root == NULL) ^ (subRoot == NULL)) return false;
        if((root == NULL) && (subRoot == NULL)) return true;
        bool check;
        if(root->val == subRoot->val){
            check = isSameTree(root, subRoot);
        }
        if(check == true) return true;
        return (isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot));
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if((p == NULL) ^ (q == NULL)) return false;
        if((p == NULL) && (q == NULL)) return true;
        if(p->val == q->val){
            if(!isSameTree(p->left, q->left)) return false;
            if(!isSameTree(p->right, q->right)) return false;
            return true;
        }
        else{
            return false;
        }
    }
};

// Another Approach
// class Solution {
// public:
//     bool isSubtree(TreeNode* root, TreeNode* subRoot) {
//         if (root == NULL) {
//             return false;
//         }
//         if (isSame(root, subRoot)) {
//             return true;
//         }
//         return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
//     }
// private:
//     bool isSame(TreeNode* root, TreeNode* subRoot) {
//         if (root == NULL && subRoot == NULL) {
//             return true;
//         }
//         if (root == NULL || subRoot == NULL) {
//             return false;
//         }
//         if (root->val != subRoot->val) {
//             return false;
//         }
//         return isSame(root->left, subRoot->left) && isSame(root->right, subRoot->right);
//     }
// };