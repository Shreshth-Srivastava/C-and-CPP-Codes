#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int arr[26] = {0};
        int arr2[26] = {0};
        for(int i=0;i<s1.size();i++) arr[s1[i] - 'a']++;
        int l = 0, r = 0;
        while(r<s2.size()){
            while(r<s2.size() && arr[s2[r] - 'a']){
                arr2[s2[r] - 'a']++;
                while(arr2[s2[r] - 'a'] > arr[s2[r] - 'a']){
                    arr2[s2[l] - 'a']--;
                    l++;
                }
                if(r-l+1 == s1.size()) return true;
                r++;
            }
            for(int j=0;j<26;j++) arr2[j] = 0;
            r++;
            l = r;
        }
        return false;
    }
};

int main(){
    Solution sol;
    cout<<"Result: "<<sol.checkInclusion("ky","ainwkckifykxlribaypk")<<endl;
    return 0;
}