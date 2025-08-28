#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Better Solution
class Trie {
public:

    Trie() {
        
    }
    
    void insert(string word) {
        Node* currentNode = &trie;
        for(int i = 0; i < word.length(); ++i) {
            currentNode = &currentNode->childrens[word[i]];
            if(i == word.length() - 1) {
                currentNode->isTerminal = true;
            }
        }
    }
    
    bool search(string word) {
        Node* currentNode = &trie;
        for(int i = 0; i < word.length(); ++i) {
            if(currentNode->childrens.count(word[i])) {
                currentNode = &currentNode->childrens[word[i]];
            } else {
                return false;
            }
        }
        return currentNode->isTerminal;
    }
    
    bool startsWith(string prefix) {
        Node* currentNode = &trie;
        for(int i = 0; i < prefix.length(); ++i) {
            if(currentNode->childrens.count(prefix[i])) {
                currentNode = &currentNode->childrens[prefix[i]];
            } else {
                return false;
            }
        }
        return true;
    }

private:
    struct Node
    {
        unordered_map<char, Node> childrens;
        bool isTerminal{false};
    };

    Node trie;
};


// NeetCode Solution

/*
class TrieNode{
public:
    TrieNode* children[26];
    bool isWord = false;

    TrieNode(){
        for(int i=0;i<26;i++) children[i] = NULL;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        int curr = 0;

        for(int i=0;i<word.size();i++){
            curr = word[i] - 'a';
            if(node->children[curr] == NULL){
                node->children[curr] = new TrieNode();
            }
            node = node->children[curr];
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        int curr = 0;

        for(int i=0;i<word.size();i++){
            curr = word[i] - 'a';
            if(node->children[curr] == NULL){
                return false;
            }
            node = node->children[curr];
        }
        return node->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        int curr = 0;

        for(int i=0;i<prefix.size();i++){
            curr = prefix[i] - 'a';
            if(node->children[curr] == NULL){
                return false;
            }
            node = node->children[curr];
        }
        return true;
    }
private:
    TrieNode* root;
};
*/

int main(){
    Trie* obj = new Trie();
    string word = "apple";
    string prefix = "app";
    obj->insert(word);
    bool param_2 = obj->search(word);
    bool param_3 = obj->startsWith(prefix);
    return 0;
}