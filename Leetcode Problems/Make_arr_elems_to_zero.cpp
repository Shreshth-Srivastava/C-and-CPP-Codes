#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// My Solution (Optimised Prefix Sum): Time Complexity --> O(N) ; Space Complexity --> O(1)

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 2;
        int l = 0, r = 0;

        for(int i=0;i<n;++i){
            r += nums[i];
        }

        int count = 0;

        for(int i=0;i<n;++i){
            if(nums[i] == 0){
                if(l == r-l) count += 2;
                if(l+1 == r-l || l == r-l+1) count++;
            }
            else{
                l += nums[i];
            }
        }

        return count;
    }
};

// My Solution (Prefix Sum): Time Complexity --> O(N) ; Space Complexity --> O(N)

/*class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 2;
        vector<int> prefix(n, 0), suffix(n, 0);

        prefix[0] = nums[0];
        suffix[n-1] = nums[n-1];

        for(int i=1;i<n;++i){
            prefix[i] = prefix[i-1] + nums[i];
        }

        for(int i=n-2;i>=0;--i){
            suffix[i] = suffix[i+1] + nums[i];
        }

        int count = 0;

        for(int i=0;i<n;++i){
            if(nums[i] == 0){
                if(prefix[i] == suffix[i]) count += 2;
                if(prefix[i]+1 == suffix[i] || prefix[i] == suffix[i]+1) count++;
            }
        }

        return count;
    }
};*/

int main(){
    Solution sol;

    // vector<int> nums = {1,0,2,0,3};
    // vector<int> nums = {0,1};
    vector<int> nums = {1,0};
    // vector<int> nums = {2,3,4,0,4,1,0};

    cout<<sol.countValidSelections(nums);

    return 0;
}