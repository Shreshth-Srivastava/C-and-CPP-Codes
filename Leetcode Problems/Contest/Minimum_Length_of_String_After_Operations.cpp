#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int minimumLength(string s) {
        if(s.size()<=2) return s.size();
        int count = s.size();
        sort(s.begin(),s.end());
        for(int i=1;i<s.size() - 1;i++){
            if(s[i-1] == s[i] && s[i+1] == s[i]){
                count -= 2;
                i++;
            }
        }
        return count;
    }
};

int main(){
    Solution sol;
    cout<<sol.minimumLength("abaacbcbb")<<endl;
    return 0;
}