#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int k, val;
    Node* prev;
    Node* next;

    Node(int key, int value){
        k = key;
        val = value;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> m;
    Node* left;
    Node* right;

    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        
        prev->next = next;
        next->prev = prev;
    }

    void insert(Node* node) {
        Node* prev = right->prev;
        Node* next = right;
        
        prev->next = node;
        next->prev = node;
        
        node->prev = prev;
        node->next = next;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        left = new Node(0,0);
        right = new Node(0,0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if(m.find(key) != m.end()){
            remove(m[key]);
            insert(m[key]);
            return m[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            remove(m[key]);
            delete m[key];
        }
        m[key] = new Node(key, value);
        insert(m[key]);
        if(m.size() > cap){
            Node* LRU = left->next;
            remove(LRU);
            m.erase(LRU->k);
            delete LRU;
        }
    }
};