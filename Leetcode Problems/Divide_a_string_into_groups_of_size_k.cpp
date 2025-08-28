#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// My Solution: Time Complexity --> O(N) ; Space Complexity --> O(N) for res

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        
        string temp = "";

        for(const auto& c: s){
            temp.append(1, c);
            if(temp.size() == k){
                res.push_back(temp);
                temp = "";
            }
        }
        
        if(temp.size() != 0){
            while(temp.size() != k){
                temp.append(1, fill);
            }
            res.push_back(temp);
        }

        return res;
    }
};

int main(){
    Solution sol;
    sol.divideString("abcdefghi", 3, 'x');
    return 0;
}