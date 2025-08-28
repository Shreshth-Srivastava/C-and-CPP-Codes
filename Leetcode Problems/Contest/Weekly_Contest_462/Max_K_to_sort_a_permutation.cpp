#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Better Solution: Time Complexity --> O(N) ; Space Complexity --> O(1)

class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int x = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            if(i != nums[i]){
                x &= i;
            }
        }
        return x == INT_MAX ? 0 : x;
    }
};

// My Solution (Wrong): Time Complexity --> O(N) ; Space Complexity --> O(N)
// Fails for test case: {0,1,2,3,4,5,6,14,8,9,10,7,12,13,11} , my op = 3 ; expected op = 2;

/*class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int cnt = 0, res = INT_MAX, n = nums.size(), minElem = INT_MAX;
        vector<int> arr;

        for(int i=0;i<n;++i){
            if(nums[i] != i){
                arr.push_back(nums[i]);
                minElem = min(minElem, nums[i]);
                cout<<nums[i]<<endl;
                cnt++;
            }
        }

        if(cnt == 0)
            return 0;

        // cout<<"Min: "<<minElem<<endl;

        for(int i = 0;i<arr.size();++i){
            // cout<<"Arr["<<i<<"]: "<<arr[i]<<endl;
            if(arr[i] != minElem)
                res = min(res, minElem & arr[i]);
        }

        return res;
    }
};*/