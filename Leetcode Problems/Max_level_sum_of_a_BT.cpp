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

typedef long long ll;

// Better Solution: Time Complexity --> O(N) ; Space Complexity --> O(W) where W is the max width of the tree

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        ll maxSum = LLONG_MIN, minLvl = LLONG_MAX, lvl = 1;
        // int maxSum = INT_MIN, minLvl = INT_MAX, lvl = 1;

        q.emplace(root);

        while(!q.empty()){
            ll lvlSize = q.size(), currSum = 0;

            while(lvlSize-- > 0){
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left){
                    q.emplace(curr->left);
                }

                if(curr->right){
                    q.emplace(curr->right);
                }

                currSum += curr->val;
            }


            if(maxSum < currSum){
                maxSum = currSum;
                minLvl = lvl;
            }
            
            lvl++;
        }

        return minLvl;
    }
};

// My Solution: Time Complexity --> O(N) ; Space Complexity --> O(W) where W is the max width of the tree

/*class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        // ll maxSum = LLONG_MIN, minLvl = LLONG_MAX;
        int maxSum = INT_MIN, minLvl = INT_MAX;

        q.push({root, 1});

        while(!q.empty()){
            pair<TreeNode*, int> curr = q.front();
            q.pop();

            int currSum = (curr.first)->val, currLvl = curr.second;
            
            if((curr.first)->left){
                q.push({(curr.first)->left, currLvl+1});
            }

            if((curr.first)->right){
                q.push({(curr.first)->right, currLvl+1});
            }

            while((q.front()).second == currLvl){
                pair<TreeNode*, int> temp = q.front();
                q.pop();

                if((temp.first)->left){
                    q.push({(temp.first)->left, currLvl+1});
                }

                if((temp.first)->right){
                    q.push({(temp.first)->right, currLvl+1});
                }

                currSum += (temp.first)->val;
            }

            if(maxSum < currSum){
                maxSum = currSum;
                minLvl = currLvl;
            }
            
        }

        return minLvl;
    }
};*/