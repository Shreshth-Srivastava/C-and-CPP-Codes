#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Better Approach
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> umap;

        for(auto x:strs)
        {
            string word = x;
            sort(word.begin(),word.end());
            umap[word].push_back(x);
        }
        
        vector<vector<string>> ans;

        if(strs.empty())
        return ans;

        for(auto x:umap)
        {
            ans.push_back(x.second);
        }

        return ans;

    }
};

// Neetcode approach
// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         unordered_map<string, vector<string>> m;
//         for (int i = 0; i < strs.size(); i++) {
//             string key = getKey(strs[i]);
//             m[key].push_back(strs[i]);
//         }
        
//         vector<vector<string>> result;
//         for (auto it = m.begin(); it != m.end(); it++) {
//             result.push_back(it->second);
//         }
//         return result;
//     }
// private:
//     string getKey(string str) {
//         vector<int> count(26);
//         for (int j = 0; j < str.size(); j++) {
//             count[str[j] - 'a']++;
//         }
        
//         string key = "";
//         for (int i = 0; i < count.size(); i++) {
//             key.append(to_string(count[i]) + '#');
//         }
//         return key;
//     }
// };