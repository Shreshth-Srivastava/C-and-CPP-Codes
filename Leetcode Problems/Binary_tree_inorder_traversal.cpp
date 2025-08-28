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

// Morris Algorithm

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

// iterative method using stack

/*
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        while(root||!s.empty()){
            if(root!=NULL){
                s.push(root);
                root=root->left;
            }
            else{
                root=s.top();
                s.pop();
                result.push_back(root->val);
                root=root->right;
            }
        }
         return result;
    }
};
*/

//  Recursive method
/*void helper(TreeNode* root,vector<int>& ans)
{
    if(root==NULL)
    {
        return ;
    }
    helper(root->left,ans);
    ans.push_back(root->val);
    helper(root->right,ans);
}
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    helper(root,ans);
    return ans;
        
}*/