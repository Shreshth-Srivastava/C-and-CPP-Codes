#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Neetcode Solution

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        vector<vector<string>> result;
        dfs(s, 0, curr, result);
        return result;
    }
private:
    void dfs(string s, int start, vector<string>& curr, vector<vector<string>>& result) {
        if (start == s.size()) {
            result.push_back(curr);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            if (isPalindrome(s, start, i)) {
                string str = s.substr(start, i - start + 1);
                curr.push_back(str);
                dfs(s, i + 1, curr, result);
                curr.pop_back();
            }
        }
    }
    bool isPalindrome(string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

// My Solution --> Needs Improvements

/*class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        helper(s, 1);
        return res;
    }
private:
    vector<string> curr;

    int isPalindrome(string s){
        if(s.size() == 1) return 1;
        else{
            for(int i = 0;i<=s.size()/2;i++){
                if(s[i] != s[s.size() - 1 - i]){
                    return 0;
                }
            }
            return 1;
        }
    }

    void helper(string s, int partitionSize){
        if(partitionSize == s.size()) return;
        string temp = "";
        int ptr1 = 0, ptr2 = 0;
        while(ptr1 <= ptr2 && ptr2 <= s.size()){
            if(ptr2-ptr1 == partitionSize){
                if(isPalindrome(temp)) curr.push_back(temp);
                temp.pop_back();
                ptr1++;
            }
            temp.push_back(s[ptr2]);
            ptr2++;
        }
        res.push_back(curr);
        curr.clear();
        helper(s, partitionSize+1);
    }
};*/

int main(){
    Solution sol;
    string s = "aaa";
    sol.partition(s);
    return 0;
}