#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

// Two Pointers method: Time Complexity --> O(N^2) ; Space Complexity --> O(1)

class Solution {
public:
    string longestPalindrome(string& s) {
        int n = s.size();
        int resIdx, resLen = 0;

        for(int i=0;i<n;i++){
            // odd cases
            int l=i, r=i;
            while(l >= 0 && r<n && s[l] == s[r]){
                if(resLen < (r-l+1)){
                    resIdx = l;
                    resLen = r-l+1;
                }
                l--; r++;
            }
            
            // even cases
            l=i, r=i+1;
            while(l >= 0 && r<n && s[l] == s[r]){
                if(resLen < (r-l+1)){
                    resIdx = l;
                    resLen = r-l+1;
                }
                l--; r++;
            }
        }

        return s.substr(resIdx, resLen);
    }
};

// Dynamic Programming: Time Complexity --> O(N^2) ; Space Complexity --> O(N^2)

// class Solution {
// public:
//     string longestPalindrome(string s) {
//         int resIdx = 0, resLen = 0;
//         int n = s.size();

//         vector<vector<bool>> dp(n, vector<bool>(n, false));

//         for (int i = n - 1; i >= 0; i--) {
//             for (int j = i; j < n; j++) {
//                 if (s[i] == s[j] && 
//                     (j - i <= 2 || dp[i + 1][j - 1])) {

//                     dp[i][j] = true;
//                     if (resLen < (j - i + 1)) {
//                         resIdx = i;
//                         resLen = j - i + 1;
//                     }
//                 }
//             }
//         }

//         return s.substr(resIdx, resLen);
//     }
// };

// Manacher's Algorithm: Time Complexity --> O(N) ; Space Complexity --> O(N)

// class Solution {
// public:
//     vector<int> manacher(string& s) {
//         string t = "#" + string(1, s[0]);
//         for (int i = 1; i < s.size(); ++i)
//             t += "#" + string(1, s[i]);
//         t += "#";
//         int n = t.size();
//         vector<int> p(n, 0);
//         int l = 0, r = 0;
//         for (int i = 0; i < n; i++) {
//             p[i] = (i < r) ? min(r - i, p[l + (r - i)]) : 0;
//             while (i + p[i] + 1 < n && i - p[i] - 1 >= 0 &&
//                    t[i + p[i] + 1] == t[i - p[i] - 1])
//                 p[i]++;
//             if (i + p[i] > r)
//                 l = i - p[i], r = i + p[i];
//         }
//         return p;
//     }
    
//     string longestPalindrome(string s) {
//         vector<int> p = manacher(s);
//         int resLen = 0, center_idx = 0;
//         for (int i = 0; i < p.size(); i++) {
//             if (p[i] > resLen) {
//                 resLen = p[i];
//                 center_idx = i;
//             }
//         }
//         int resIdx = (center_idx - resLen) / 2;
//         return s.substr(resIdx, resLen);
//     }
// };