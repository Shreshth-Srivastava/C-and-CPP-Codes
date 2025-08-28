/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//My Solution

void DFS(int target, int *max, struct TreeNode *root){
    struct TreeNode *ptr = root;
    if(ptr == NULL) return;
    else{
        if(ptr->left != NULL){
            int a = abs(target - (ptr->left)->val);
            if(a > *max) *max = a;
        }
        if(ptr->right != NULL){
            int b = abs(target - (ptr->right)->val);
            if(b > *max) *max = b;
        }
        DFS(target, max, ptr->left);
        DFS(target, max, ptr->right);
        return;
    }
}

void NxtTarget(int *max, struct TreeNode *root){
    if(root == NULL) return;
    else{
        DFS(root->val, max, root);
        NxtTarget(max, root->left);
        NxtTarget(max, root->right);
        return;
    }
}

int maxAncestorDiff(struct TreeNode* root){
    int max = 0;
    NxtTarget(&max, root);
    return max;
}

//Best Solution

// int helper(struct TreeNode * root, int max, int min) {
//     if (root == NULL) {
//         return max - min;
//     }
//     if (root->val > max) {
//         max = root->val;
//     }

//     if (root->val < min) {
//         min = root->val;
//     }
//     int left = helper(root->left, max, min);
//     int right = helper(root->right, max, min);
//     if (left > right) {
//         return left;
//     }
//     return right;
// }
// int maxAncestorDiff(struct TreeNode* root) {
//     if (root == NULL) {
//         return 0;
//     }
//     return helper(root, root->val, root->val);
// }