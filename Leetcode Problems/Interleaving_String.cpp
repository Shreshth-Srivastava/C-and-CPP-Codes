#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Bottom-Up Approach: Time Complexity --> O(n*m) ; Space Complexity --> O(n*m) ; Where m is the length of the string s1 and n is the length of the string s2.

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length(), n = s2.length();
        if (m + n != s3.length()) {
            return false;
        }

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[m][n] = true;

        for (int i = m; i >= 0; i--) {
            for (int j = n; j >= 0; j--) {
                if (i < m && s1[i] == s3[i + j] && dp[i + 1][j]) {
                    dp[i][j] = true;
                }
                if (j < n && s2[j] == s3[i + j] && dp[i][j + 1]) {
                    dp[i][j] = true;
                }
            }
        }
        return dp[0][0];
    }
};

// Top-Down Approach - 2: Time Complexity --> O(n*m) ; Space Complexity --> O(n*m) ; Where m is the length of the string s1 and n is the length of the string s2.

// class Solution {
//     vector<vector<int>> dp;
// public:
//     bool isInterleave(string s1, string s2, string s3) {
//         int m = s1.length(), n = s2.length();
//         if (m + n != s3.length()) return false;
//         dp = vector<vector<int>>(m + 1, vector<int>(n + 1, -1));
//         return helper(0, 0, s1, s2, s3);
//     }

// private:
//     bool helper(int i, int j, string& s1, string& s2, string& s3){
//         if(i+j == s3.size()){
//             return (i == s1.size()) && (j == s2.size());
//         }
        
//         if(dp[i][j] != -1) return dp[i][j];

//         bool res = false;

//         if(i<s1.size() && s1[i] == s3[i+j]){
//             res = helper(i+1, j, s1, s2, s3);
//         }
//         if(!res && j<s2.size() && s2[j] == s3[i+j]){
//             res = helper(i, j+1, s1, s2 ,s3);
//         }
//         dp[i][j] = res;
//         return res;
//     }
// };

// Top-Down Approach - 1

// class Solution {
// public:
//     bool isInterleave(string s1, string s2, string s3) {
//         return helper(0, 0, s1, s2, s3);
//     }

// private:
//     unordered_map<string, bool> dp;

//     bool helper(int i, int j, string& s1, string& s2, string& s3){
//         if(i+j == s3.size()) return (i == s1.size()) && (j == s2.size());

//         string key = to_string(i) + "-" + to_string(j);
        
//         if(dp.find(key) != dp.end()) return dp[key];

//         if(i<s1.size() && s1[i] == s3[i+j]){
//             if(helper(i+1, j, s1, s2, s3)) return true;
//         }
//         if(j<s2.size() && s2[j] == s3[i+j]){
//             if(helper(i, j+1, s1, s2 ,s3)) return true;
//         }
//         dp[key] = false;
//         return false;
//     }
// };

// Recursion

// class Solution {
// public:
//     bool isInterleave(string s1, string s2, string s3) {
//         return helper(0, 0, s1, s2, s3);
//     }

// private:
//     bool helper(int i, int j, string& s1, string& s2, string& s3){
//         if(i+j == s3.size()) return true;
//         char temp1 = s1[i], temp2 = s2[j], temp3 = s3[i+j];
//         if(i<s1.size() && s1[i] == s3[i+j]){
//             if(helper(i+1, j, s1, s2, s3)) return true;
//         }
//         if(j<s2.size() && s2[j] == s3[i+j]){
//             if(helper(i, j+1, s1, s2 ,s3)) return true;
//         }
//         return false;
//     }
// };

int main(){
    Solution sol;
    string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
    cout<<"Result: "<<sol.isInterleave(s1, s2, s3);
    return 0;
}