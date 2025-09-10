#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Time Complexity --> O(N) ; Space Complexity --> O(N)

class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        long long count=0;
        int n= nums.size();
        stack<int> st;

        for(int i=0; i<n; i++){
            while(!st.empty() && nums[i]>=nums[st.top()]){
                if((i-st.top())>1) count++;
                st.pop();
            }
            if(!st.empty() && (i-st.top())>1) count++;
            st.push(i);
        }

        return count;
    }
};

int main(){
    Solution sol;

    vector<int> nums = {2,5,3,1,4};
    sol.bowlSubarrays(nums);

    return 0;
}