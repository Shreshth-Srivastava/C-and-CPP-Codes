#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

// My Solution: Time Complexity --> O(N) ; Space Complexity --> O(N)

class Solution {
public:
    string processStr(string s) {
        string res = "";

        for(const auto& c: s){
            if(c == '*'){
                if(!res.empty())
                    res.pop_back();
                else
                    continue;
            }
            else if(c == '#'){
                if(!res.empty())
                    res.append(res);
                else
                    continue;
            }
            else if(c == '%')
                if(!res.empty())
                    reverse(res.begin(), res.end());
                else
                    continue;
            else
                res.append(1,c);
        }

        return res;
    }
};