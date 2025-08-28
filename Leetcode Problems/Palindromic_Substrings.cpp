#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

// Two Pointers method: Time Complexity --> O(N^2) ; Space Complexity --> O(1)

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), res = 0;
        for(int i=0;i<n;i++){
            // odd cases
            int l=i, r=i;
            while(l >= 0 && r<n && s[l] == s[r]){
                l--; r++; res++;
            }
            
            // even cases
            l=i, r=i+1;
            while(l >= 0 && r<n && s[l] == s[r]){
                l--; r++; res++;
            }
        }
        return res;
    }
};