#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Time Complexity --> O(NLogN) ; Space Complexity --> O(1)

class Solution {
public:
    int maxSum(vector<int>& nums) {
        int sum = 0, n = nums.size();
        sort(nums.begin(), nums.end());

        if(nums[n-1]<0) return nums[n-1];
        else{
            for(int i=0;i<n;i++){
                if((i!=0 && nums[i]>0 && nums[i]!=nums[i-1])||(i==0) && nums[i]>0) sum=sum+nums[i];
            }
        }

        return sum;   
    }
};

// class Solution {
// public:
//     int maxSum(vector<int>& nums) {
//         int freq[201] = {0};
//         for (int &num : nums) {
//             freq[100 + num]++;
//         }

//         int curSum = INT_MIN, maxSum = INT_MIN;
//         for (int i = 200; i >= 0; --i) {
//             if (freq[i] > 0) {
//                 curSum = curSum >= 0 ?  curSum + i - 100 : i - 100; 
//             }
//             maxSum = max(curSum, maxSum);
//         }
//         return maxSum;        
//     }
// };


int main(){
    Solution sol;
    // vector<int> nums = {1,2,3,4,5};
    // vector<int> nums = {1,1,0,1,1};
    // vector<int> nums = {1,2,-1,-2,1,0,-1};
    // vector<int> nums = {-100};
    vector<int> nums = {-20, 20};
    cout<<sol.maxSum(nums);
    return 0;
}