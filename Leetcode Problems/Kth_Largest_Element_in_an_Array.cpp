#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// My Solution

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            if(heap.size() < k) heap.push(nums[i]);
            else if(nums[i] >= heap.top()){
                heap.pop();
                heap.push(nums[i]);
            }
        }
        return heap.top();
    }
private:
    priority_queue<int, vector<int>, greater<int>> heap;
};

// QuickSelect Approach

/*
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int index = nums.size() - k;
        return quickSelect(nums, index, 0, nums.size() - 1);
    }
private:
    int quickSelect(vector<int>& nums, int k, int l, int r){
        int pivot = nums[r];
        int p_pos = l;
        for (int i = l; i < r; ++i){
            if (nums[i] <= pivot){
                swap(nums[i], nums[p_pos]);
                ++p_pos;
            }
        }
        swap(nums[p_pos], nums[r]);
        if (k < p_pos)
            return quickSelect(nums, k, l, p_pos - 1);
        if (k > p_pos)
            return quickSelect(nums, k, p_pos + 1, r);
        return nums[p_pos];
    }
};
*/

int main(){
    Solution sol;
    vector<int> nums = {-1,2,0};
    cout<<sol.findKthLargest(nums, 2);
    return 0;
}