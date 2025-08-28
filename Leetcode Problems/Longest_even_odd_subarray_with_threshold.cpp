#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// My Solution: Time Complexity --> O(N) ; Space Complexity --> O(1)

class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int res = 0, l = -1, r = 0, n = nums.size(), req = 0;
        
        while(r < n){
            if(nums[r] % 2 == req && nums[r] <= threshold){
                if(l == -1){
                    l = r;
                }

                res = max(res, r - l + 1);
                req = !(req);
            }
            else{
                if(nums[r] % 2 == 0 && nums[r] <= threshold){
                    l = r;
                    req = 1;
                }
                else{
                    l = -1;
                    req = 0;
                }
            }

            r++;
        }

        return res;
    }
};