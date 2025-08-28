#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// My Solution: Time Complexity --> O(2^N) ; Space Complexity --> O(N) for recursive stack calls

class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        int n = nums.size();
        
        for(const auto& num: nums){
            if(target%num != 0) return false;
        }

        long long partition2 = 1;

        if(dfs(0, nums, 1, target)){
            if(s.size() == 0) return false;

            for(int i=0;i<n;++i){
                if(s.find(i) == s.end()){
                    partition2 *= nums[i];
                }
            }

        }
        return partition2 == target ? true : false;
    }
private:
    unordered_set<int> s;

    bool dfs(int start, vector<int>& nums, long long currTarget, long long& target){
        if(start >= nums.size()){
            if(currTarget == target){
                return true;
            }
            return false;
        }


        bool take = dfs(start+1, nums, currTarget*nums[start], target);
        
        if(take){
            s.insert(start);
            return true;
        }

        bool notTake = dfs(start+1, nums, currTarget, target);

        return notTake;
    }
};

int main(){
    Solution sol;
    // vector<int> nums = {11,22,5,10};
    // cout<<sol.checkEqualPartitions(nums, 110);
    // vector<int> nums = {2,4,6};
    // cout<<sol.checkEqualPartitions(nums, 24);
    // vector<int> nums = {3,1,6,8,4};
    // cout<<sol.checkEqualPartitions(nums, 24);
    // vector<int> nums = {3,2,6,9};
    // cout<<sol.checkEqualPartitions(nums, 6);
    // vector<int> nums = {1,3,8};
    // cout<<sol.checkEqualPartitions(nums, 24);
    vector<int> nums = {10,2,20,1};
    cout<<sol.checkEqualPartitions(nums, 20);
    return 0;
}