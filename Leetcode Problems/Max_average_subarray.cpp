#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Cleaner Solution

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = accumulate(nums.begin(), nums.begin() + k, 0);
        double ans = sum;

        for (int i = k; i < nums.size(); ++i) {
            sum += nums[i] - nums[i - k];
            ans = max(ans, sum);
        }

        return ans / k;
    }
};

// My Solution: Time Complexity --> O(N) ; Space Complexity --> O(1)

/*class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double curr = 0, res = -99999;
        int l = 0, r = -1;
        int n = nums.size();

        while(r < n){
            while(r-l+1 < k){
                r++;
                curr += (double)nums[r];
            }

            double avg = curr / k;
            res = max(res, avg);

            curr -= (double)nums[l];
            l++;
            r++;
            if(r < n)
                curr += (double)nums[r];
        }

        return res;
    }
};*/

int main(){
    Solution sol;

    // vector<int> arr = {-1};
    vector<int> arr = {1,12,-5,-6,50,3};

    cout<<sol.findMaxAverage(arr ,4);

    return 0;
}