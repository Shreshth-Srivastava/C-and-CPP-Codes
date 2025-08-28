#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Better Solution

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0)
            return ans;
        string output;
        int index = 0;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl","mno","pqrs","tuv","wxyz"};
        solve(digits, output, index, ans, mapping);
        return ans;
    }
private:
    void solve(string digit, string output, int index, vector<string>& ans, string mapping[] ) {
        
        //base case
        if(index >= digit.length()) {
            ans.push_back(output);
            return;
        }
        int number = digit[index] - '0';
        string value = mapping[number];
        
        for(int i=0; i<value.length(); i++) {
            output.push_back(value[i]);
            solve(digit, output, index+1, ans, mapping);
            output.pop_back();
        }
        
    }
};

// Neetcode Solution

/*class Solution {
public:
    string curr = "";
    vector<string> result;
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return result;
        unordered_map<char, string> m = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        helper(digits, 0, m);
        return result;
    }
private:
    void helper(string digits, int index, unordered_map<char, string> m){
        if(index == digits.size()){
            result.push_back(curr);
            return;
        }
        string str = m[digits[index]];
        for(int i=0;i<str.size();i++){
            curr.push_back(str[i]);
            helper(digits, index+1, m);
            curr.pop_back();
        }
    }
};*/