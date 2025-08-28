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

// Recursive Solution , Better Performance

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        return check(root->left, root->right);
    }

    bool check(TreeNode* p, TreeNode* q){
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;
        return p->val == q->val && (check(p->left, q->right) && check(p->right, q->left));
    }
};

// My Solution , Iterative Solution

/*class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root->left != NULL) stk1.push({root->left, (root->left)->val});
        else stk1.push({nullptr, 999});

        if(root->right != NULL) stk2.push({root->right, (root->right)->val});
        else stk2.push({nullptr, 999});

        while(!stk1.empty() && !stk2.empty()){
            TreeNode* currleft = stk1.top().first;
            int lval = stk1.top().second;
            TreeNode* currright = stk2.top().first;
            int rval = stk2.top().second;
            if(lval != rval) return false;
            stk1.pop();
            stk2.pop();
            if(currleft != nullptr){
                if(currleft->right != nullptr) stk1.push({currleft->right, (currleft->right)->val});
                else stk1.push({nullptr, 999});

                if(currleft->left != nullptr) stk1.push({currleft->left, (currleft->left)->val});
                else stk1.push({nullptr, 999});
            }

            if(currright != nullptr){
                if(currright->left != nullptr) stk2.push({currright->left, (currright->left)->val});
                else stk2.push({nullptr, 999});

                if(currright->right != nullptr) stk2.push({currright->right, (currright->right)->val});
                else stk2.push({nullptr, 999});
            }
        }
        return true;
    }
private:
    stack<pair<TreeNode*, int>> stk1;
    stack<pair<TreeNode*, int>> stk2;
};*/

int main(){
    Solution sol;
    TreeNode child = TreeNode(0);
    TreeNode root = TreeNode(1, &child, nullptr);
    cout<<sol.isSymmetric(&root);
    return 0;
}