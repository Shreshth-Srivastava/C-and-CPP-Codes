#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

// Sliding Window: Time Complexity --> O(N) ; Space Complexity --> O(M) where N--> size of s and M--> total num of unique characters in s and t

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";

        unordered_map<char, int> countT, window;
        for (char c : t) {
            countT[c]++;
        }

        int have = 0, need = countT.size();
        pair<int, int> res = {-1, -1};
        int resLen = INT_MAX;
        int l = 0;

        for (int r = 0; r < s.length(); r++) {
            char c = s[r];
            window[c]++;

            if (countT.count(c) && window[c] == countT[c]) {
                have++;
            }

            while (have == need) {
                if ((r - l + 1) < resLen) {
                    resLen = r - l + 1;
                    res = {l, r};
                }

                window[s[l]]--;
                if (countT.count(s[l]) && window[s[l]] < countT[s[l]]) {
                    have--;
                }
                l++;
            }
        }

        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
    }
};

// My Solution --> Incomplete

// class Solution {
// public:
//     string minWindow(string s, string t) {
//         if(t.size() > s.size()) return "";
//         vector<int> arrT(52, 0);
//         vector<int> arrS(52, 0);
//         int start = 0, resLen = INT_MAX;
//         pair<int, int> res;

//         for(const auto& c: t){
//             arrT[c - 'A']++;
//         }

//         int cnt = accumulate(arrT.begin(), arrT.end(), 0);
//         int temp = cnt;

//         for(int i=0;i<s.size(); i++){
//             arrS[s[i] - 'A']++;
//             if(arrS[s[i] - 'A'] == arrT[s[i] - 'A']) temp -= arrS[s[i] - 'A'];
//             while(temp == 0){
//                 if(i - start < resLen){
//                     res.first = start;
//                     res.second = i;
//                     resLen = i - start + 1;
                    
//                     // start++;
//                     // temp++;
//                     // for(int j=0;j<52;j++) arrS[j] = 0;
//                 }   

//                 arrS[s[start] - 'A']--;
//                 if(arrT[s[start] - 'A'] && arrS[s[start] - 'A'] < arrT[s[start] - 'A']) temp++;
//                 start++;
//             }
//         }
//         return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
//     }
// };

int main(){
    Solution sol;
    string s = "ADOBECODEBANC", t = "ABC";
    // string s = "ab", t = "b";
    cout<<sol.minWindow(s, t);
    return 0;
}