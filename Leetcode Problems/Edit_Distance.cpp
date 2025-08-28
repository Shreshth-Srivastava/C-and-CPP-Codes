#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Bottom-Up Approach: Time Complexity --> O(m*n) ; Space Complexity --> O(m*n) ; where m is the length of word1 and n is the length of word2

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, 0));

        for (int j = 0; j <= word2.length(); j++) {
            dp[word1.length()][j] = word2.length() - j;
        }
        for (int i = 0; i <= word1.length(); i++) {
            dp[i][word2.length()] = word1.length() - i;
        }

        for (int i = word1.length() - 1; i >= 0; i--) {
            for (int j = word2.length() - 1; j >= 0; j--) {
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    dp[i][j] = 1 + min(dp[i + 1][j], 
                                   min(dp[i][j + 1], dp[i + 1][j + 1]));
                }
            }
        }
        return dp[0][0];
    }
};

// Top-Down Approach

// class Solution {
// public:
//     int minDistance(string word1, string word2) {
//         int m = word1.size(), n = word2.size();
//         vector<vector<int>> dp(m, vector<int>(n, 0));
//         return helper(0, 0, word1, word2, m, n, dp);
//     }
// private:

//     int helper(int i, int j, string word1, string word2, int m, int n, vector<vector<int>>& dp){
//         if(i == m) return n - j;
//         if(j == n) return m - i;

//         if(dp[i][j] != 0){
//             return dp[i][j];
//         }

//         int minOp;
        
//         if(word1[i] == word2[j]){
//             return helper(i+1, j+1, word1, word2, m, n, dp);
//         }
//         else{
//             int op1 = helper(i, j+1, word1, word2, m, n, dp); // Insert Op
//             int op2 = helper(i+1, j, word1, word2, m, n, dp); // Delete Op
//             int op3 = helper(i+1, j+1, word1, word2, m, n, dp); // Replace Op
//             minOp = min(op1, op2);
//             minOp = min(minOp, op3);
//         }
//         dp[i][j] = minOp+1;
//         return dp[i][j];
//     }
// };


// Recursion

// class Solution {
// public:
//     int minDistance(string word1, string word2) {
//         int m = word1.size(), n = word2.size();
//         return helper(0, 0, word1, word2, m, n);
//     }
// private:
//     int helper(int i, int j, string word1, string word2, int m, int n){
//         if(i == m) return n - j;
//         if(j == n) return m - i;

//         int minOp;
        
//         if(word1[i] == word2[j]){
//             return helper(i+1, j+1, word1, word2, m, n);
//         }
//         else{
//             int op1 = helper(i, j+1, word1, word2, m, n); // Insert Op
//             int op2 = helper(i+1, j, word1, word2, m, n); // Delete Op
//             int op3 = helper(i+1, j+1, word1, word2, m, n); // Replace Op
//             minOp = min(op1, op2);
//             minOp = min(minOp, op3);
//         }
//         return minOp+1;
//     }
// };

int main(){
    Solution sol;
    sol.minDistance("horse", "ros");
    return 0;
}