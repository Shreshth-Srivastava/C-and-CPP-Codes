#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* 
Note: Q1/Q2: Use a sliding window to determine the places at which there is a subarray with consecutive increasing integers. Keep track of a left pointer, initialized to 0. Go through the array, and when we encounter a new number, if it is not equal to the previous number + 1, set our left pointer to the current index. If the distance between our current pointer and the left pointer is k, set the answer array at the left pointer equal to nums[i], then increment the left pointer. Once we're done the main loop, go through the answer array and set all remaining values to -1.
Q3/Q4: Note that we only need to keep track of the 3 largest elements of each row. Then, we can run a simple O(n^3) algorithm that goes through all triplets of rows and brute forces all combinations of the 3 largest elements in each row. This passes Q3 but has a massive constant factor of 27, so it may TLE on Q4. However if you simply check to see if the maximum value of each selected row is greater than the current best answer, you can still AC Q4 (constant optimization letsgooooo!!!)
*/

// Improved Version

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int ptr1 = 0, ptr2 = 0, n = nums.size();
        vector<int> res(n-k+1, -1);
        while(ptr1<=ptr2 && ptr2<n){
            if(ptr1 == ptr2){
                if((ptr2-ptr1) == k-1){
                    res[ptr1] = nums[ptr2];
                    ptr1++;
                    ptr2++;
                    continue;
                }
                else{
                    ptr2++;
                    continue;
                }
            }
            else{
                if(nums[ptr2] != nums[ptr2-1]+1){
                    ptr1++;
                    ptr2 = ptr1;
                    continue;
                }
            }
            if((ptr2-ptr1) == k-1){
                res[ptr1] = nums[ptr2];
                ptr1++;
                ptr2++;
                continue;
            }
            ptr2++;
        }
        return res;
    }
};

// My Solution

/*class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int ptr1 = 0, ptr2 = 0, n = nums.size(), counter = 0, Max;
        vector<int> res(n-k+1, -1);
        while(ptr1<=ptr2 && ptr2<n){
            if(ptr1 == ptr2){
                Max = nums[ptr1];
                if((ptr2-ptr1) == k-1){
                    res[counter] = Max;
                    counter++;
                    ptr1++;
                    ptr2++;
                    continue;
                }
                else{
                    ptr2++;
                    continue;
                }
            }
            else{
                if(nums[ptr2] == nums[ptr2-1]+1) Max = nums[ptr2];
                else{
                    Max = -1;
                    counter++;
                    ptr1++;
                    ptr2 = ptr1;
                    continue;
                }
            }
            if((ptr2-ptr1) == k-1){
                res[counter] = Max;
                counter++;
                ptr1++;
                ptr2++;
                continue;
            }
            ptr2++;
        }
        return res;
    }
};*/

int main(){
    Solution sol;
    vector<int> array = {3,1,2,1,4,4,88,89,90,4};
    sol.resultsArray(array, 3);
    return 0;
}