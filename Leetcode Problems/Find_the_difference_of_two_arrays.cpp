#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// My Solution: Time Complexity --> O(N) ; Space Complexity --> O(1)

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<bool> s1(2001, false), s2(2001, false);
        vector<vector<int>> res(2);

        for(const auto& a: nums1)
            s1[a+1000] = true;

        for(const auto& b: nums2){
            s2[b+1000] = true;
            if(s1[b+1000])
                s1[b+1000] = false;
        }
            
        for(const auto& a: nums1){
            if(s2[a+1000])
                s2[a+1000] = false;
        }

        for(int i=0;i<2001;++i){
            if(s1[i])
                res[0].push_back(i-1000);
        }

        for(int i=0;i<2001;++i){
            if(s2[i])
                res[1].push_back(i-1000);
        }

        return res;
    }
};