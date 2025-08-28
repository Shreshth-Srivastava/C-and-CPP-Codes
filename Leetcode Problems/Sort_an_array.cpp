#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void QuickSort(vector<int>& nums, int start, int end){
        if(start>=end) return;
        int s = start, e = end, mid = start+(end-start)/2, pivot = nums[mid];
        while(s<=e){
            while(nums[s]<pivot) s++;
            while(nums[e]>pivot) e--;
            if(s<=e){
                int temp = nums[s];
                nums[s] = nums[e];
                nums[e] = temp;
                s++;
                e--;
            }
        }
        QuickSort(nums, start, e);
        QuickSort(nums, s, end);
    }
    
    vector<int> sortArray(vector<int>& nums) {
        QuickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {5,2,3,1};
    sol.sortArray(nums);
    return 0;
}