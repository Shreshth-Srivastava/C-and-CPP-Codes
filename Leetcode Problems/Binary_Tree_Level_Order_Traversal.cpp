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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        q.push(root);
        while(!q.empty()){
            int count = q.size();
            vector<int> arr;
            for(int i=0;i<count;i++){
                TreeNode* currNode = q.front();
                q.pop();
                arr.push_back(currNode->val);
                if(currNode->left != NULL) q.push(currNode->left);
                if(currNode->right != NULL) q.push(currNode->right);
            }
            res.push_back(arr);
        }
        return res;
    }
private:
    queue<TreeNode*> q;
};

int main(){
    Solution sol;
    TreeNode second1 = TreeNode(15);
    TreeNode second2 = TreeNode(7);
    TreeNode first1 = TreeNode(2);
    TreeNode first2 = TreeNode(20, &second1, &second2);
    TreeNode root = TreeNode(3, &first1, &first2);
    vector<vector<int>> res = sol.levelOrder(&root);
    for(auto itr: res){
        cout<<"{";
        for(auto it: itr){
            cout<<" "<<it<<" ";
        }
        cout<<"}";
    }
    return 0;
}