#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

// Better Appraoch: Time Complexity --> O(26*N) ==> O(N) ; Space Complexity --> O(26)
/*class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        char ch[26];
        for (int i=0; i<26; i++)
            ch[i] = 'a' + i;

        for (int i=0; i<s1.size(); i++) {
            char toReplace = max(ch[s1[i]-'a'], ch[s2[i]-'a']);
            char replaceWith = min(ch[s1[i]-'a'], ch[s2[i]-'a']);
            for (int i=0; i<26; i++)
                if (ch[i] == toReplace)
                    ch[i] = replaceWith;
        }
        
        for (int i = 0; i<baseStr.size(); i++)
            baseStr[i] = ch[baseStr[i]-'a'];

        return baseStr;
    }
};*/

// My Solution (Union-Find): Time Complexity --> O(26*N + B) ==> O(N + B) where N is the size of string s1 (or s2) and B is the size of the string baseStr ; Space Complexity --> O(26 + N)

class Solution {
public:
    string smallestEquivalentString(string& s1, string& s2, string& baseStr) {
        int n = s1.size();
        unordered_map<char,int> m;
        vector<char> arr(n, '{');

        for(int i=0;i<n;++i){
            if(m.find(s1[i]) == m.end()){
                m.insert({s1[i], i});
                arr[i] = s1[i];
            }
        }

        for(int i=0;i<n;++i){
            int idx = m[s1[i]], idx2 = -1;
            char temp = arr[idx];
            char curr = s2[i];
            

            if(m.find(curr) != m.end()){
                idx2 = m[s2[i]];
                char temp2 = arr[idx2];
                curr = temp2;
            }

            if(curr < temp){
                arr[idx] = curr;
            }

            if(idx2 != -1){
                updateGroup(idx2, idx, m);
                // arr[idx2] = arr[idx];
                // m[temp] = idx2;
                // m[s2[i]] = idx2;
            }

            m[s2[i]] = idx;
        }

        for(int i=0;i<baseStr.size();++i){
            if(m.find(baseStr[i]) != m.end()){
                int idx = m[baseStr[i]];
                char temp = arr[idx];
                baseStr[i] = temp;
            }
        }

        return baseStr;
    }
private:
    void updateGroup(int currValue, int update, unordered_map<char,int>& m){
        for(auto& [key, value]: m){
            if(value == currValue){
                value = update;
            }
        }
    }
};

int main(){
    Solution sol;

    // string s1 = "parker", s2 = "morris", baseStr = "parser";
    // cout<<sol.smallestEquivalentString(s1, s2, baseStr);

    // string s1 = "hello", s2 = "world", baseStr = "hold";
    // cout<<sol.smallestEquivalentString(s1, s2, baseStr);

    string s1 = "leetcode", s2 = "programs", baseStr = "sourcecode";
    cout<<sol.smallestEquivalentString(s1, s2, baseStr);

    // int temp = 123;
    // cout<<(char)temp;

    return 0;
}