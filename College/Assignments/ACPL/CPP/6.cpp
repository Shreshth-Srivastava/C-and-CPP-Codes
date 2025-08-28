#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    string reverse_words(string s) {
        istringstream iss(s);
        vector<string> words;
        string word;
        while (iss >> word) words.push_back(word);
        reverse(words.begin(), words.end());
        string result;
        for (string w : words) result += w + " ";
        return result;
    }
};

int main(){
    Solution sol;
    cout<<sol.reverse_words("Hello! My name is Shreshth Srivastava");
    return 0;
}