#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Better Solution
    void rotate(vector<int>& nums, int k){
        k=k%nums.size();
        reverse(nums.begin(),nums.begin()+(nums.size()-k));

        reverse(nums.begin()+(nums.size()-k),nums.end());

        reverse(nums.begin(),nums.end());
    }

    // My Solution

    /*void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < 2) return;
        vector<int> temp(n, 0);
        for (int i = 0; i < n; i++)
        {
            if(i+k >= n){
                temp[(i+k)%n] = nums[i];
            }
            else temp[i+k] = nums[i];
        }
        nums.swap(temp);
    }*/
};

int main(){
    Solution sol;
    vector<int> nums = {-1,-100,3,99};
    sol.rotate(nums, 2);
    return 0;
}