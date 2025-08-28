#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int longest_word_length(vector<string>& words) {
        int max_len = 0;
        for (string w : words)
            if (w.size() > max_len) max_len = w.length();
        return max_len;
    }

};

int main(){
    Solution sol;
    vector<string> words = {"A", "AB", "ABC", "DE", "F"};
    cout<<sol.longest_word_length(words);
    return 0;
}