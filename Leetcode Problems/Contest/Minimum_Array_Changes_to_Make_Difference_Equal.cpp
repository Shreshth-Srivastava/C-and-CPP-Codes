#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size(), count = 0;
        int X = abs(nums[0] - nums[n-1]);
        for(int i=1;i<n/2;i++){
            if(abs(nums[i]-nums[n-i-1]) != X){
                if(abs(nums[i]-nums[n-i-1]) >= k){
                    count += 2;
                }
                else count++;
            }
        }
        return count;
    }
};

int main(void){
    Solution sol;
    vector<int> nums = {1,0,1,2,4,3};
    cout<<sol.minChanges(nums, 4)<<endl;
    return 0;
}