#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Greedy Solution: Time Complexity --> O(N) ; Space Complexity --> O(1)

class Solution {
public:
    bool checkValidString(string s) {
        int leftMin = 0, leftMax = 0;

        for (char c : s) {
            if (c == '(') {
                leftMin++;
                leftMax++;
            } else if (c == ')') {
                leftMin--;
                leftMax--;
            } else {
                leftMin--;
                leftMax++;
            }
            if (leftMax < 0) {
                return false;
            }
            if (leftMin < 0) {
                leftMin = 0;
            }
        }
        return leftMin == 0;
    }
};

// Top-Down DP Approach: Time Complexity-->O(N^2) ; Space Complexity -->O(N^2)

// class Solution {
// public:
//     bool checkValidString(string s) {
//         int n = s.size();
//         memo = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));
//         return dfs(0, 0, s);
//     }

// private:
//     vector<vector<int>> memo;

//     bool dfs(int i, int open, const string& s) {
//         if (open < 0) return false;
//         if (i == s.size()) return open == 0;

//         if (memo[i][open] != -1) return memo[i][open] == 1;

//         bool result;
//         if (s[i] == '(') {
//             result = dfs(i + 1, open + 1, s);
//         } else if (s[i] == ')') {
//             result = dfs(i + 1, open - 1, s);
//         } else {
//             result = (dfs(i + 1, open, s) || 
//                       dfs(i + 1, open + 1, s) || 
//                       dfs(i + 1, open - 1, s));
//         }
        
//         memo[i][open] = result ? 1 : 0;
//         return result;
//     }
// };

// Recursive Approach: Time-Complexity --> O(3^N) ; Space Complexity --> O(N)

// class Solution {
// public:
//     bool checkValidString(string s) {
//         return dfs(0, 0, s);
//     }

// private:
//     bool dfs(int i, int open, const string& s) {
//         if (open < 0) return false;
//         if (i == s.size()) return open == 0;

//         if (s[i] == '(') {
//             return dfs(i + 1, open + 1, s);
//         } else if (s[i] == ')') {
//             return dfs(i + 1, open - 1, s);
//         } else {
//             return dfs(i + 1, open, s) ||
//                    dfs(i + 1, open + 1, s) ||
//                    dfs(i + 1, open - 1, s);
//         }
//     }
// };

int main(){
    Solution sol;
    // string s = "(*)";
    string s = "(((((()*)(*)*))())())(()())())))((**)))))(()())()";
    cout<<sol.checkValidString(s);
    return 0;
}