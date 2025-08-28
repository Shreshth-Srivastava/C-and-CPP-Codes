#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Better Solution: Time Complexity --> O(N) ; Space Complexity --> O(1)

class Solution {
public:
    string makeFancyString(string s) {
        int idx = 0;

        for(int i = 0; i < s.size(); i++){
            if(idx < 2 || s[idx - 1] != s[idx - 2] || s[idx - 1] != s[i])
                s[idx++] = s[i];
        }

        return s.substr(0, idx);
    }
};

// My Solution: Time Complexity --> O(N) ; Space Complexity --> O(N)
/*

class Solution {
public:
    string makeFancyString(string s) {
        string res = "";
        int idx = -1, cnt = 1;

        for(const auto& c: s){
            if(idx == -1){
                res.append(1, c);
                cnt = 1;
                idx++;
                continue;
            }

            if(c != res[idx]){
                res.append(1, c);
                cnt = 1;
                idx++;
            }
            else{
                if(cnt < 2){
                    res.append(1, c);
                    idx++;
                    cnt++;
                }
            }
        }

        return res;
    }
};

*/