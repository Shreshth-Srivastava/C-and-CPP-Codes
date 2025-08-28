#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Improved Solution

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n+2, 0);
        for(const auto &query: queries){
            diff[query[0]] += 1;
            diff[query[1]+1] -= 1;
        }

        int count = 0;
        for(int i=0;i<n;i++){
            count += diff[i];
            if(nums[i] != 0) nums[i] -= count;
            if(nums[i] > 0) return false;
        }

        return true;
    }
};

// My Solution: Time Complexity --> O(N+M) ; Space Complexity --> O(N)

// class Solution {
// public:
//     bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
//         int n = nums.size();
//         vector<int> diff(n+2, 0);
//         for(const auto query: queries){
//             diff[query[0]] += 1;
//             diff[query[1]+1] -= 1;
//         }
//         for(int i=1;i<n+2;i++){
//             diff[i] += diff[i-1];
//         }

//         for(int i=0;i<n;i++){
//             if(nums[i] > diff[i]) return false;
//         }

//         return true;
//     }
// };

int main(){
    Solution sol;
    vector<int> nums = {1,0,1};
    vector<vector<int>> queries = {{0,2}};
    cout<<sol.isZeroArray(nums, queries);
    return 0;
}