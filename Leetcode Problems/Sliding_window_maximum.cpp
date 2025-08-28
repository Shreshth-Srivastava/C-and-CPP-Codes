#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Deque Approach: Time Complexity --> O(N) ; Space Complexity --> O(N)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size(), l = 0, r = 0;
        vector<int> res(n-k+1);
        deque<int> q;

        while(r < n){
            while(!q.empty() && nums[q.back()] < nums[r]){
                q.pop_back();
            }
            q.push_back(r);

            if(l > q.front()){
                q.pop_front();
            }

            if(r+1 >= k){
                res[l] = nums[q.front()];
                l++;
            }
            r++;
        }

        return res;
    }
};

// My Solution: Time Complexity --> O(N^2) ; Space Complexity --> O(1)

// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         int l = 0, n = nums.size();
//         vector<int> res;

//         for(int i=0;i<=n-k;i++){
//             int maxElem = INT_MIN;
//             for(int j=0;j<k;j++){
//                 maxElem = max(maxElem, nums[i+j]);
//             }
//             res.push_back(maxElem);
//         }

//         return res;
//     }
// };

int main(){
    Solution sol;
    // vector<int> nums = {1,3,-1,-3,5,3,6,7};
    vector<int> nums = {1, -1};
    sol.maxSlidingWindow(nums, 1);
    return 0;
}