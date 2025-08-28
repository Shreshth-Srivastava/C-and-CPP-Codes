#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        quickSort(0, nums.size()-1, nums);
    }
private:
    void quickSort(int low, int high, vector<int>& nums){
        if(low >= high) return;
        int s = low, e = high, m = s + (e-s)/2, pivot = nums[m];
        while(s<=e){
            while(nums[s] < pivot) s++;
            while(nums[e] > pivot) e--;
            if(s<=e){
                swap(s, e, nums);
                s++;e--;
            }
        }
        quickSort(low, e, nums);
        quickSort(s, high, nums);
    }

    void swap(int i, int j, vector<int>& nums){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,0,2,1,1,0};
    sol.sortColors(nums);
    for(int num: nums){
        cout<<num<<"  ";
    }
    return 0;
}