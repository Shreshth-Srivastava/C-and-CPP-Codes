// Manacher's Algorithm is a linear-time algorithm used to find the longest palindromic substring in a given string. It works by transforming the input string to handle even- and odd-length palindromes uniformly by inserting a special character (like #) between every character and at the boundaries. It then iterates through the transformed string, maintaining a center and a right boundary of the current longest palindrome. For each character, it uses symmetry to minimize the work by referring to its mirror around the center. If the palindrome centered at the current position extends beyond the current known boundary, the center and right boundary are updated. It keeps track of the maximum length found and its center position. After the loop, it converts the center and length back to the original string's indices to retrieve the actual longest palindrome. The key optimization lies in avoiding rechecking characters that are known to match by leveraging previously computed results. This makes the algorithm run in O(n) time. It's especially useful when a brute-force approach would be too slow.

#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> manacher(string& s) {
        string t = "#" + string(1, s[0]);
        for (int i = 1; i < s.size(); ++i)
            t += "#" + string(1, s[i]);
        t += "#";
        int n = t.size();
        vector<int> p(n, 0);
        int l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            p[i] = (i < r) ? min(r - i, p[l + (r - i)]) : 0;
            while (i + p[i] + 1 < n && i - p[i] - 1 >= 0 &&
                   t[i + p[i] + 1] == t[i - p[i] - 1])
                p[i]++;
            if (i + p[i] > r)
                l = i - p[i], r = i + p[i];
        }
        return p;
    }
    
    string longestPalindrome(string s) {
        vector<int> p = manacher(s);
        int resLen = 0, center_idx = 0;
        for (int i = 0; i < p.size(); i++) {
            if (p[i] > resLen) {
                resLen = p[i];
                center_idx = i;
            }
        }
        int resIdx = (center_idx - resLen) / 2;
        return s.substr(resIdx, resLen);
    }
};