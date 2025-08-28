#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int res = 0;
        vector<int> s(26,0);
        for(auto i: allowed) s[i - 'a']++;
        for(int i=0;i<words.size();i++){
            bool flag = true;
            for(auto j: words[i]){
                if(!s[j - 'a']) flag = false;
            }
            if(flag) res++;
        }
        return res;
    }
};

int main(){
    Solution sol;
    string str = "ab";
    vector<string> s = {"ad","bd","aaab","baa","badab"};
    cout<<sol.countConsistentStrings(str, s);
    return 0;
}