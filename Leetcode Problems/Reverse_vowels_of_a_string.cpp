#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// My Solution: Time Complexity --> O(N) ; Space Complexity --> O(1)

class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size();
        int l = 0, r = n - 1;

        while(l<r){
            while(l < n && s[l] != 'a' && s[l] != 'A' 
            && s[l] != 'e' && s[l] != 'E' 
            && s[l] != 'i' && s[l] != 'I'
            && s[l] != 'o' && s[l] != 'O'
            && s[l] != 'u' && s[l] != 'U'){
                l++;
            }

            while(r >= 0 && s[r] != 'a' && s[r] != 'A' 
            && s[r] != 'e' && s[r] != 'E' 
            && s[r] != 'i' && s[r] != 'I'
            && s[r] != 'o' && s[r] != 'O'
            && s[r] != 'u' && s[r] != 'U'){
                r--;
            }

            if(l<r){
                char temp = s[l];
                s[l] = s[r];
                s[r] = temp;
                l++;r--;
            }
        }

        return s;
    }
};

int main(){
    Solution sol;

    // cout<<sol.reverseVowels("IceCreAm")<<endl;
    cout<<sol.reverseVowels("leetcode")<<endl;

    return 0;
}