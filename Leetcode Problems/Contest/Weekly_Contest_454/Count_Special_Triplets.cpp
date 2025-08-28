#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// My Solution: Time Complexity --> O(N) ; Space Complexity --> O(N)

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, vector<int>> m;
        int n = nums.size();
        unsigned int res = 0, r = 0;
        vector<int> l(n, 0);
        const unsigned int mod = 1e9 + 7;

        for(int i=0;i<n;++i){
            if(m.find(nums[i]*2) != m.end()){
                l[i] = m[nums[i]*2].size();
            }
            m[nums[i]].push_back(i);
        }

    
        for(int i=1;i<n-1;++i){
            if(l[i] > 0){
                int total = m[nums[i]*2].size();
                if(nums[i] != 0){
                    r = total - l[i];
                }
                else{
                    r = total - l[i] - 1;
                }
                // res += (l[i]%mod)*(r%mod);
                // res%mod;
                res = (res + (l[i] % mod * r % mod)) % mod;
                r=0;
            }
        }

        return res;
    }
};

int main(){
    Solution sol;

    vector<int> nums = {6,3,6};
    // vector<int> nums = {6,3,6,6};
    // vector<int> nums = {6,6,3,6,6};
    // vector<int> nums = {0,1,0,0};
    // vector<int> nums = {8,4,2,8,4};

    cout<<sol.specialTriplets(nums);

    return 0;
}