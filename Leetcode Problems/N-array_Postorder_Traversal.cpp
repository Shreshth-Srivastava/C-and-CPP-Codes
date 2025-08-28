#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

// Iterative Solution

class Solution{
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        if(root == NULL) return res;
        stack<Node*> stk;
        stk.push(root);
        while(!stk.empty()){
            Node* curr = stk.top();
            stk.pop();
            int n = (curr->children).size();
            for(int i=0;i<n;i++){
                stk.push((curr->children)[i]);
            }
            res.push_back(curr->val);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// Iterative Solution without reversal

/*class Solution{
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        if(root == NULL) return res;
        stack<pair<Node*, bool>> stk;
        stk.push({root, false});
        while(!stk.empty()){
            Node* curr = stk.top().first;
            bool flag = stk.top().second;
            if(!flag){
                stk.top().second = true;
                int n = (curr->children).size();
                for(int i=n-1;i>=0;i--){
                    stk.push({(curr->children)[i], false});
                }
            }
            else{
                stk.pop();
                res.push_back(curr->val);
            }
        }
        return res;
    }
};*/

// Recursive Solution

/*class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        if(root == NULL) return res;
        int n = (root->children).size();
        for(int i=0;i<n;i++){
            helper((root->children)[i], res);
        }
        res.push_back(root->val);
        return res;
    }
private:
    void helper(Node* root, vector<int>& res){
        if((root->children).empty()){
            res.push_back(root->val);
            return;
        }
        int n = (root->children).size();
        for(int i=0;i<n;i++){
            helper((root->children)[i], res);
        }
        res.push_back(root->val);
    }
};*/

int main(){
    Solution sol;
    Node node1 = Node(5);
    Node node2 = Node(6);

    Node node3 = Node(3);
    vector<Node*> child3 = {&node1, &node2};
    node3.children = child3;

    Node node4 = Node(2);
    Node node5 = Node(4);

    Node node6 = Node(1);
    vector<Node*> child1 = {&node3, &node4, &node5};
    node6.children = child1;

    vector<int> res = sol.postorder(&node6);

    for(auto it:res) cout<<it<<" ";

    return 0;
}