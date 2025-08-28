#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// My Solution: Time Complexity --> O(NlogN) ; Space Complexity --> O(N)

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> temp(n);

        for(int i = 0;i < n;++i){
            temp[i] = {nums[i],i};
        }

        sort(temp.begin(), temp.end());
        
        vector<int> res(k,-1);

        sort(temp.end() - k, temp.end(), [](const auto& a, const auto& b){
            return a.second < b.second;
        });

        for(int i = n-1;i >= 0;--i){
            if(k>0){
                res[k-1] = temp[i].first;
                k--;
            }
            else{
                break;
            }
        }


        return res;
    }
};

int main(){
    Solution sol;

    // vector<int> nums = {2,1,3,3};
    // int k = 2;

    vector<int> nums = {50, -75};
    int k = 2;

    sol.maxSubsequence(nums, k);

    return 0;
}