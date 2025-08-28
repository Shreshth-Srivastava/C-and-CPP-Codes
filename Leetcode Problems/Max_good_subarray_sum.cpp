#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Kadane's Algorithm Approach: Time Complexity --> O(N) ; Space Complexity --> O(N)

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long res = LLONG_MIN;
        vector<long long> psum{0};
        unordered_map<int, int> m;
        
        for (int i = 0; i < nums.size(); ++i) {
            psum.push_back(psum.back() + nums[i]);

            if (auto it = m.find(nums[i] - k); it != end(m))
                res = max(res, psum[i + 1] - psum[it->second]);

            if (auto it = m.find(nums[i] + k); it != end(m))
                res = max(res, psum[i + 1] - psum[it->second]);

            if (auto it = m.find(nums[i]); it == end(m) || psum[i] - psum[it->second] <= 0)
                m[nums[i]] = i;
        }
        return res == LLONG_MIN ? 0 : res;
    }
};

// My Solution (TLE): Time Complexity --> O(N^2) ; Space Complexity --> O(N)

// class Solution {
// public:
//     long long maximumSubarraySum(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<long long> prefix(n+1,0);
//         prefix[0] = 0;

//         for(int i=1;i<=n;++i){
//             prefix[i] = prefix[i-1] + nums[i-1];
//         }

//         int ptr1 = 0, ptr2 = 1;
//         long long res = LLONG_MIN;

//         while(ptr1 < n-1){
//             while(ptr2 < n && ptr2-ptr1+1 <= k){
//                 if(abs(nums[ptr1] - nums[ptr2]) == k){
//                     res = max(res, prefix[ptr2+1] - prefix[ptr1]);
//                 }
//                 ptr2++;
//             }
//             ptr1++;
//             ptr2 = ptr1+1;
//         }

//         return res == LLONG_MIN ? 0 : res;
//     }
// };

int main(){
    Solution sol;

    vector<int> nums = {1,2,3,4,5,6};
    int k = 1;

    // vector<int> nums = {6,0,-1,-6};
    // int k = 1;

    cout<<sol.maximumSubarraySum(nums, k);

    return 0;
}