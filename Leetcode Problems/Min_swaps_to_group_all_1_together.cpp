#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Better Solution

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int cnt1=0, cnt0=0, sz=nums.size();
        cnt1=count(nums.begin(), nums.end(), 1);
        
        int windowsize=cnt1;
        for(int i =0;i<windowsize;i++){
            if(nums[i]==0) cnt0++;
        }
        int mn=cnt0;
        for(int i =windowsize;i<windowsize+sz;i++){
            if(nums[i%sz]==0) cnt0++;
            if(nums[i-windowsize]==0) cnt0--;
            mn=min(mn, cnt0);
        }
        return mn;
    }
};

// My Solution

/*class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size(), window = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == 1) window++;
        }
        for(int j=0;j<window;j++){
            nums.push_back(nums[j]);
        }
        int result, ptr1 = 0, ptr2 = window-1, current = 0;
        for(int k=0;k<window;k++){
            if(nums[k] == 0) current++;
        }
        result = current;
        while(ptr1 <= ptr2 && ptr2<n+window-1){
            if(nums[ptr1] == 0) current--;
            ptr1++;
            ptr2++;
            if(nums[ptr2] == 0) current++;
            result = min(current, result);
        }
        return result;
    }
};*/

int main(){
    Solution sol;
    vector<int> nums = {1,1,0,0,1};
    cout<<sol.minSwaps(nums)<<endl;
    return 0;
}