#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low=0, high=n-1;
        
        while(low<high){
            if(nums[low] <= nums[high]) return nums[low];
            int mid = low + (high-low)/2;
            if(nums[low] > nums[mid]){
                high=mid;
            } else if(nums[mid] > nums[high]) {
                low=mid+1;
            } 
        }
        if(nums[low] <= nums[high]) return nums[low];
        return -1;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {3,1,2};
    cout<<sol.findMin(nums)<<endl;
    return 0;
}