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

// Recursive Solution --> Better Result

class Solution {
public:
    int goodNodes(TreeNode* root) {
        int result = 0;
        dfs(root, root->val, result);
        return result;
    }
private:
    void dfs(TreeNode* root, int maxSoFar, int& result) {
        if (root == NULL) {
            return;
        }
        
        if (root->val >= maxSoFar) {
            result++;
        }
        
        dfs(root->left, max(maxSoFar, root->val), result);
        dfs(root->right, max(maxSoFar, root->val), result);
    }
};

// My Solution --> Iterative Solution

/*class Solution {
public:
    int goodNodes(TreeNode* root) {
        int res = 0;
        stk.push({root, root->val});
        while(!stk.empty()){
            TreeNode* curr = (stk.top()).first;
            int currmax = (stk.top()).second;
            stk.pop();
            if(curr->val >= currmax){
                res++;
                currmax = max(currmax, curr->val);
                if(curr->right != NULL) stk.push({curr->right, currmax});
                if(curr->left != NULL) stk.push({curr->left, currmax});
            }
            else{
                if(curr->right != NULL) stk.push({curr->right, currmax});
                if(curr->left != NULL) stk.push({curr->left, currmax});
            }
        }
        return res;
    }
private:
    stack<pair<TreeNode*, int>> stk;
};*/

int main(){
    Solution sol;
    TreeNode first1 = TreeNode(4);
    TreeNode first2 = TreeNode(2);

    TreeNode second1 = TreeNode(3, &first1, &first2);

    TreeNode root = TreeNode(3, &second1, NULL);

    cout<<sol.goodNodes(&root);

    return 0;
}