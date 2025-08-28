#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Neetcode Solution (Bottom-Up Approach) [Space Optimized]: Time Complexity --> O(N) ; Space Complexity --> O(1)

class Solution {
public:
    int numDecodings(string s) {
        int dp = 0, dp2 = 0;
        int dp1 = 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '0') {
                dp = 0;
            } else {
                dp = dp1;
                if (i + 1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i + 1] < '7')) {
                    dp += dp2;
                }
            }
            dp2 = dp1;
            dp1 = dp;
            dp = 0;
        }
        return dp1;
    }
};

// Neetcode Solution (Bottom-Up Approach): Time Complexity --> O(N) ; Space Complexity --> O(N)

// class Solution {
// public:
//     int numDecodings(string s) {
//         vector<int> dp(s.size() + 1);
//         dp[s.size()] = 1;
//         for (int i = s.size() - 1; i >= 0; i--) {
//             if (s[i] == '0') {
//                 dp[i] = 0;
//             } else {
//                 dp[i] = dp[i + 1];
//                 if (i + 1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i + 1] < '7')) {
//                     dp[i] += dp[i + 2];
//                 }
//             }
//         }
//         return dp[0];
//     }
// };

// Neetcode Solution (Top-Down Approach): Time Complexity --> O(N) ; Space Complexity --> O(N)


// class Solution {
// public:
//     int numDecodings(string s) {
//         unordered_map<int, int> dp;
//         dp[s.size()] = 1;
//         return dfs(s, 0, dp);
//     }

// private:
//     int dfs(string s, int i, unordered_map<int, int>& dp) {
//         if (dp.count(i)) {
//             return dp[i];
//         }
//         if (s[i] == '0') {
//             return 0;
//         }

//         int res = dfs(s, i + 1, dp);
//         if (i + 1 < s.size() && (s[i] == '1' || 
//             s[i] == '2' && s[i + 1] < '7')) {
//             res += dfs(s, i + 2, dp);
//         }
//         dp[i] = res;
//         return res;
//     }
// };

int main(){
    Solution sol;
    string s = "226";
    int res = sol.numDecodings(s);
    cout<<"Result: "<<res;
    return 0;
}