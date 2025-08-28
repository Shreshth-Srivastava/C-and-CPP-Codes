#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// My Solution: Time Complexity --> O(N) ; Space Complexity --> O(1)

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxElem = INT_MIN, res = 1, n = nums.size(), l = 0;

        for(int r = 0;r<n;++r){
            if(nums[r] > maxElem){
                maxElem = nums[r];
                l = r;
                res = 1;
            }

            else if(nums[r] == maxElem){
                if(l == -1){
                    l = r;
                }
                res = max(res, r - l + 1);
            }
            
            else{
                l = -1;
            }
        }

        return res;
    }
};

int main(){
    Solution sol;

    // vector<int> nums = {2,1,1,1,1,3,1,1,3,3,3,2,2,2,3,3};
    vector<int> nums = {96317,96317,96317,96317,96317,96317,96317,96317,96317,279979};
    cout<<sol.longestSubarray(nums);

    return 0;
}