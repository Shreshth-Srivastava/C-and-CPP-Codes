#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Better Solution
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) 
    {
        int n = nums.size();
        long long imax = 0, dmax = 0, res = 0;

        for (int k = 0; k < n; k++)
        {
            res = max(res, dmax * nums[k]);
            dmax = max(dmax, imax - nums[k]);
            imax = max(imax, (long long)nums[k]);
        }
        return res;
    }
};

// My Solution

// class Solution {
// public:
//     long long maximumTripletValue(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> prefix(n, 0), suffix(n, 0);
//         int maxVal = 0;

//         for(int i=0;i<n;++i){
//             maxVal = max(maxVal, nums[i]);
//             prefix[i] = maxVal;
//         }

//         maxVal = 0;

//         for(int i=n-1;i>=0;--i){
//             maxVal = max(maxVal, nums[i]);
//             suffix[i] = maxVal;
//         }

//         long long res = 0;
//         long long  temp;

//         for(int i=1;i<n-1;++i){
//             temp = ((long long)prefix[i-1] - (long long)nums[i])*(long long)suffix[i+1];
//             res = max(res, temp);
//         }

//         return res;
//     }
// };

int main(){
    Solution sol;
    // vector<int> nums = {8,6,3,13,2,12,19,5,19,6,10,11,9};
    vector<int> nums = {10,13,6,2};
    long long res = sol.maximumTripletValue(nums);
    cout<<"\nResult: "<<res;
}