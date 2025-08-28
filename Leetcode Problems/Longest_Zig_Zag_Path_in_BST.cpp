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

// Better Solution: Time Complexity --> O(N) ; Space Complexity --> O(logN)

class Solution {
public:
    int pathLength = 0;
    void dfs(TreeNode* node, bool goLeft, int steps) {
        if (node == nullptr) {
            return;
        }
        pathLength = max(pathLength, steps);
        if (goLeft) {
            dfs(node->left, false, steps + 1);
            dfs(node->right, true, 1);
        } else {
            dfs(node->left, false, 1);
            dfs(node->right, true, steps + 1);
        }
    }

    int longestZigZag(TreeNode* root) {
        dfs(root, true, 0);
        return pathLength;
    }
};

// My Solution: Time Complexity --> O(N^2) ; Space Complexity --> O(logN)

/*typedef long long ll;

class Solution {
public:
    int longestZigZag(TreeNode* root) {
        ll countL = 0, countR = 0;

        dfs(root, false, countL);
        dfs(root, true, countR);

        ll count = max(countL, countR);
        ll L = root->left != nullptr ? (ll)longestZigZag(root->left) : 0;
        ll R = root->right != nullptr ? (ll)longestZigZag(root->right) : 0;

        return max(max(count, L), R);
    }

private:
    void dfs(TreeNode* node, bool dirn, ll& count){
        if(node == nullptr)
            return;

        if(dirn){
            if(node->right != nullptr){
                count++;
                dfs(node->right, !dirn, count);
            }
            else{
                return;
            }
        }
        else{
            if(node->left != nullptr){
                count++;
                dfs(node->left, !dirn, count);
            }
        }
    }
};
*/