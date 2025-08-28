#include<iostream>
#include<bits/stdc++.h>
using namespace std;

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

int main(){
    Solution sol;
    string str = "cbbd";
    cout<<sol.longestPalindrome(str);
    return 0;
}