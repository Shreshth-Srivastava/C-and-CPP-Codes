#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Better Solution: Time Complexity --> O(N); Space Complexity --> O(N) for ans

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        int n = nums.size();

        int start = 0;
        for(int i=0;i<n;i++){
            if (nums[i] == key){
                int left = max(0,i-k);
                int right = min(n-1,i+k);

                while(start<=right){
                    if (start>=left) ans.push_back(start);
                    start++;
                }
            }
        }


        return ans;
    }
};

// My Solution: Time Complexity --> O(N) ; Space Complexity --> O(N)

/*class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> prefix(n+1, INT_MAX), suffix(n+1, INT_MAX);

        for(int i=1;i<=n;++i){
            if(nums[i-1] == key){
                prefix[i] = i-1;
            }
            else{
                prefix[i] = prefix[i-1];
            }
        }

        for(int i=n-1;i>=0;--i){
            if(nums[i] == key){
                suffix[i] = i;
            }
            else{
                suffix[i] = suffix[i+1];
            }
        }

        vector<int> res;

        for(int i=0;i<n;++i){
            int temp = min(abs(prefix[i+1] - i), abs(suffix[i] - i));
            if(temp <= k){
                res.push_back(i);
            }
        }

        return res;
    }
};*/

int main(){
    Solution sol;

    vector<int> nums = {3,4,9,1,3,9,5};
    int key = 9, k = 1;

    // vector<int> nums = {2,2,2,2,2};
    // int key = 2, k = 2;

    sol.findKDistantIndices(nums, key, k);

    return 0;
}