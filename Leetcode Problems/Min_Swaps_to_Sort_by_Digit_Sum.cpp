#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Cycle Detection Approach: Time Complexity --> O(NlogN) ; Space Complexity --> O(N)

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size(), res = 0;
        vector<pair<pair<int, int>, int>> arr;

        for(int i=0;i<n;i++){
            int temp = digitSum(nums[i]);
            arr.push_back({{temp, nums[i]}, i});
        }

        sort(arr.begin(), arr.end());
        
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (visited[i] == true || arr[i].second == i) continue;
            int c = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = arr[j].second;
                c++;
            }
            if (c > 1) res += c - 1;
        }

        return res;
        
    }
private:
    int digitSum(int a){
        int res = 0;
        while(a!=0){
            res += a%10;
            a /= 10;
        }
        return res;
    }
};

int main(){
    Solution sol;
    // vector<int> nums = {18, 43, 34, 16};
    vector<int> nums = {277993448,416038674,616955867,539372283};
    cout<<sol.minSwaps(nums);
    return 0;
}