#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

// class Solution {
// public:
//     bool hasMatch(string s, string p) {
//         int ind = p.find("*");
//         string p1 = p.substr(0, ind), p2 = p.substr(ind+1, p.size()-ind-1);
//         if(p1.size() + p2.size()  == 0) return true;
//         ind = 0;
//         if(p1.size()) {
//             ind = s.find(p1);
//             if(ind < 0) return false;
//         }
//         if(p2.size()) ind = s.find(p2, ind + p1.size());
//         return (ind >= 0);
//     }
// };

// My Solution: Time Complexity --> O(N*M) ; Space Complexity --> O(M)

class Solution {
public:
    bool hasMatch(string s, string p) {
        if(p.size() == 1) return true;

        string sub1 = "", sub2 = "";
        string* curr = &sub1;
        for(const auto& str: p){
            if(str == '*'){
                curr = &sub2;
                continue;
            }
            *curr += str;
        }
        
        int index = isSubstring(s, sub1, 0);
        if(index == -1) return false;

        index = isSubstring(s, sub2, index);
        if(index == -1) return false;

        return true;
    }
private:
    int isSubstring(string& s, string& p, int index){
        if(p.size() == 0) return index;
        int s_idx = index, p_idx = 0;
        for(int i=index;i<s.size();i++){
            p_idx = 0;
            if(s[i] == p[p_idx++]){
                s_idx = i+1;
                for(s_idx;p_idx<p.size();s_idx++){
                    if(s[s_idx] != p[p_idx]) break;
                    else p_idx++;
                }
                if(p_idx == p.size()) return s_idx;
            }
        }
        return -1;
    }
};

int main(){
    Solution sol;
    // string s = "leetcode", p = "ee*e";
    // string s = "car", p = "c*v";
    // string s = "tokk", p = "t*t";
    // string s = "xks", p = "s*";
    // string s = "ojjju", p = "*o";
    // string s = "nrnrs", p = "*nn";
    string s = "kvb", p = "k*v";
    cout<<sol.hasMatch(s, p);
    return 0;
}