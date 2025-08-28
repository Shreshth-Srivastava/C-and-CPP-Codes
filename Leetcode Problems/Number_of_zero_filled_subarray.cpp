#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// My Solution: Time Complexity --> O(N) ; Space Complexity --> O(1)

typedef long long ll;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        ll res = 0;

        int l = 0, r = 0, n = nums.size();

        while(r<n){
            if(nums[r] == 0){
                l = r;

                while(r < n && nums[r] == 0)
                    r++;

                ll winSize = r - l;

                res += (ll)(winSize*(winSize+1))/2;
            }
            
            r++;
        }

        return res;
    }
};