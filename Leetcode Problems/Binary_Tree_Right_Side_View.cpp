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

// Another Approach

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        helper(root, ans, 0);
        return ans; 
    }
private:
    void helper(TreeNode* root, vector<int> &ans, int level){
        if(root==NULL) return;
        if(level == ans.size()) ans.push_back(root->val);
        helper(root->right,ans, level+1);
        helper(root->left, ans, level+1);
    }
};

// My Solution

/*class Solution {
public:
    vector<int> rightSideView(TreeNode* root){
        vector<int> res;
        if(root == NULL) return res;
        q.push(root);
        while(!q.empty()){
            int count = q.size();
            for(int i=0;i<count;i++){
                TreeNode* currNode = q.front();
                q.pop();
                if(i == 0) res.push_back(currNode->val);
                if(currNode->right != NULL) q.push(currNode->right);
                if(currNode->left != NULL) q.push(currNode->left);
            }
        }
        return res;
    }
private:
    queue<TreeNode*> q;
};*/

int main(){
    Solution sol;
    TreeNode second1 = TreeNode(4);
    // TreeNode second2 = TreeNode(4);
    TreeNode first1 = TreeNode(2, &second1, NULL);
    TreeNode first2 = TreeNode(3);
    TreeNode root = TreeNode(1, &first1, &first2);
    vector<int> res = sol.rightSideView(&root);
    for(auto itr: res){
        cout<<itr<<" ";
    }
    return 0;
}