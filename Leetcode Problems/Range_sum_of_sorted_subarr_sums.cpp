#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> temp;
        long sum;
        for(int i=0;i<n;i++){
            sum = 0;
            for(int j=i;j<n;j++){
                sum += nums[j];
                temp.push_back(sum);
            }
        }
        sort(temp.begin(), temp.end());
        sum = 0;
        for(int i=left-1;i<right;i++){
            sum += temp[i];
        }
        return sum%((int)pow(10,9) + 7);
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,2,3,4};
    cout<<sol.rangeSum(nums, 4, 1, 5);
    return 0;
}