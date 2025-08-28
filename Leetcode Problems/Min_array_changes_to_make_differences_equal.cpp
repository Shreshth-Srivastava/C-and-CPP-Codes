#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> cost(k + 1, 0);  // Cost array to track changes for each difference
        
        // Process the first half of the array and compare with the second half
        for (int i = 0; i < n / 2; ++i) {
            int a = nums[i], b = nums[n - i - 1];
            if (a > b) {
                swap(a, b);  // Ensure a <= b
            }

            cost[0]++;  // Initial change count
            cost[b - a]--;  // Reduce cost for exact difference match
            if (b - a < k) {
                cost[b - a + 1]++;  // Increment for range extension
            }
            int mx = max(b, k - a) + 1;  // Calculate the maximum relevant value
            if (mx <= k) {
                cost[mx]++;  // Increment for upper range values
            }
        }

        // Calculate minimum changes using prefix sums
        int ans = cost[0];
        for (int i = 1; i <= k; ++i) {
            cost[i] += cost[i - 1];  // Propagate changes
            ans = min(ans, cost[i]);  // Track minimum changes
        }

        return ans;  // Minimum changes required
    }
};

// class Solution {
// public:
//     int minChanges(vector<int>& nums, int k) {
//         if(nums.size() == 2) return 0;
//         int n = nums.size(), res = INT_MAX;

//         unordered_set<int> s;
//         vector<pair<int, int>> arr(n/2, {0,0});

//         for(int i=0;i<n/2;++i){
//             int temp = abs(nums[i]-nums[n-i-1]);
//             s.insert(temp);
//             int threshold = max(max(nums[i], nums[n-i-1]), k-min(nums[i],nums[n-i-1]));
//             arr[i].first = temp;
//             arr[i].second = threshold;
//         }

//         for(const auto& elem:s){
//             int temp = 0;
//             for(const auto& num: arr){
//                 if(num.first != elem){
//                     if(num.second < elem) temp += 2;
//                     else temp++;
//                 }
//             }
//             res = min(temp, res);
//         }

//         return res;
//     }
// };

// class Solution {
// public:
//     int minChanges(vector<int>& nums, int k) {
//         if(nums.size() == 2) return 0;
//         int n = nums.size(), res = 0;

//         int X = INT_MIN;
//         int count = INT_MIN;
//         unordered_map<int, int> m;

//         for(int i=0;i<n/2;++i){
//             int temp = abs(nums[i]-nums[n-i-1]);
//             m[temp]++;
//             if(m[temp] == count){
//                 X = min(X, temp);
//             }
//             if(m[temp] > count){
//                 X = temp;
//                 count = m[temp];
//             }
//         }

//         for(int i=0;i<n/2;i++){
//             if(abs(nums[i]-nums[n-i-1]) != X){
//                 if(max(max(nums[i], nums[n-i-1]), k-min(nums[i],nums[n-i-1])) < X){
//                     res += 2;
//                 }
//                 else res++;
//             }
//         }
//         return res;
//     }
// };

int main(){
    Solution sol;

    // vector<int> nums = {1,0,0,1,0,1,1,0,0,0,1,1,1,1,0,0};
    // cout<<sol.minChanges(nums, 1);

    // vector<int> nums = {1,10,5,1,4,6,4,2,4,9,7,9,0,11};
    // cout<<sol.minChanges(nums, 12);

    // vector<int> nums = {1,1,1,1,0,0,0,5,4,3,19,17,16,15,15,15,19,19,19,19};
    // cout<<sol.minChanges(nums, 20);

    return 0;
}