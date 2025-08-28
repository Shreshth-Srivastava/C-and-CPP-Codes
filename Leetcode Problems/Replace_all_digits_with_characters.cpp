#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// My Solution: Time Complexity --> O(N) ; Space Complexity --> O(1)

class Solution {
public:
    string replaceDigits(string s) {
        for(int i=1;i<s.size();i+=2){
            s[i] = shift(s[i-1], s[i]);
        }
        return s;
    }
private:
    char shift(char c, char i){
        int temp = (int)c;
        int idx = i - '0';
        return (char)(temp + idx);
    }
};

int main(){
    Solution sol;
    sol.replaceDigits("a1c1e1");
    return 0;
}