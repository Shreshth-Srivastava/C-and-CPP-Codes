#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

// Editorial Solution: Time Complexity --> O(N) ; Space Complexity --> O(1)

class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, res = 0;
        while (i < chars.size()) {
            int groupLength = 1;
            while (i + groupLength < chars.size() && chars[i + groupLength] == chars[i]) {
                groupLength++;
            }
            chars[res++] = chars[i];
            if (groupLength > 1) {
                for (char c : to_string(groupLength)) {
                    chars[res++] = c;
                }
            }
            i += groupLength;
        }
        return res;
    }
};

int main(){
    Solution sol;

    vector<char> chars = {'a','b','b','b','b','b','b','b','b','b','b','b','b'};
    sol.compress(chars);
    
    return 0;
}