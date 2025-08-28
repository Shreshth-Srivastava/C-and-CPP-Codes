#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

// NeetCode Solution, Complexity --> Time: O(Edges + Nodes) == O(N) ; Space: O(N)

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;

        unordered_map<Node*, Node*> nodes;
        Node* copy = new Node(node->val);
        nodes[node] = copy;

        queue<Node*> q;
        q.push(node);

        while(!q.empty()){
            Node* curr = q.front();
            q.pop();

            for(int i = 0;i<curr->neighbors.size();i++){

                Node* neighbor = curr->neighbors[i];
                if(nodes.find(neighbor) == nodes.end()){
                    nodes[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }

                nodes[curr]->neighbors.push_back(nodes[neighbor]);
            }
        }

        return copy;
    }
};

// Another Approach
/*
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) {
            return NULL;
        } 
        if (m.find(node) == m.end()) {
            m[node] = new Node(node->val);
            for (int i = 0; i < node->neighbors.size(); i++) {
                Node* neighbor = node->neighbors[i];
                m[node]->neighbors.push_back(cloneGraph(neighbor));
            }
        }
        return m[node];
    }
private:
    unordered_map<Node*, Node*> m;
};
*/