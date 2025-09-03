#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// My Solution: Time Complexity --> O(N) ; Space Complexity --> O(N)

class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        unordered_map<int, TreeNode*> m;

        const int n = traversal.size();
        int dash = 0, i = 0;

        while(i < n){
            while(i < n && traversal[i] == '-'){
                dash++;
                i++;
            }

            int val = 0;

            while(i < n && traversal[i] != '-'){
                val = val*10 + (traversal[i] - '0');
                i++;
            }

            TreeNode* node = new TreeNode(val);

            if(dash > 0){
                TreeNode* parent = m[dash-1];
                if(!parent->left){
                    parent->left = node;
                }
                else{
                    parent->right = node;
                }
            }

            m[dash] = node;
            dash = 0;
        }

        return m[0];
    }
};

int main(){
    Solution sol;

    sol.recoverFromPreorder("1-2--3---4-5--6---7");

    return 0;
}