#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        unsigned int i = 1;
        string word, prev;
        while(i < words.size())
        {
            word = words[i];
            prev = words[i-1];
            if(word.length() != prev.length()){
                i++;
                continue;
            }
            sort(word.begin(),word.end());
            sort(prev.begin(),prev.end());
            
            if(prev == word){
                words.erase(words.begin() + i);
                continue;
            }
            i++;
        }
        return words;
    }
};

int main(){
    Solution sol;
    vector<string> words = {"abba","baba","bbaa","cd","cd"};
    sol.removeAnagrams(words);
    for(auto it: words){
        cout<<it<<" ";
    }
    return 0;
}