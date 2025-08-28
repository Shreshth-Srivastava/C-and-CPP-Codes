#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[nums[0]];
        
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

// Cyclic Sort Approach

/*class Solution {
public:
    void cyclesort(vector<int>& arr , int n){
        int i=0;
        while(i<n){
            int correct=arr[i]-1;
            if(arr[i] != arr[correct]) swap(arr,i,correct);
            else i++;
        }
    }
    void swap(vector<int>& arr , int a , int b){
        int temp = arr[a];
        arr[a]=arr[b];
        arr[b]=temp;
    }
    int findDuplicate(vector<int>& nums) {
        cyclesort(nums, nums.size());
        for(int i=0;i<nums.size();i++){
            if(nums[i]-1 != i) return nums[i];
        }
        return -1;
    }
};*/