#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<bool> hash(10000, false);
        int l = 0, n = nums.size(), res = INT_MIN, curr = 0;

        for(int r = 0;r<n;++r){
            if(!hash[nums[r]]){
                curr += nums[r];
                hash[nums[r]] = true;
            }
            else{
                while(hash[nums[r]]){
                    curr -= nums[l];
                    hash[nums[l]] = false;
                    l++;
                }

                curr += nums[r];
                hash[nums[r]] = true;
            }

            res = max(res, curr);
        }

        return res;
    }
};

int main(){
    Solution sol;

    vector<int> nums = {1, 9, 7, 10, 7, 8, 8, 2, 2, 2, 3, 1, 5, 7, 7, 10, 10, 4, 3, 8};
    cout<<sol.maximumUniqueSubarray(nums);

    return 0;
}