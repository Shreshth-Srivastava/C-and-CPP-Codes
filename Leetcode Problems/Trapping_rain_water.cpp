#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Two Pointer Approach: Time Complexity --> O(N) ; Space Complextiy --> O(1)

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }

        int l = 0, r = height.size() - 1;
        int leftMax = height[l], rightMax = height[r];
        int res = 0;
        while (l < r) {
            if (leftMax < rightMax) {
                l++;
                leftMax = max(leftMax, height[l]);
                res += leftMax - height[l];
            } else {
                r--;
                rightMax = max(rightMax, height[r]);
                res += rightMax - height[r];
            }
        }
        return res;
    }
};

// Prefix & Suffix Approach: Time Complexity --> O(N) ; Space Complexity --> O(1)

// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n = height.size();
//         int maxL = 0, maxR = 0;
//         vector<int> maxLeft(n, -1);
//         vector<int> maxRight(n, -1);

//         for(int i=0;i<n;i++){
//             maxLeft[i] = maxL;
//             maxL = max(maxL, height[i]);
//         }

//         for(int i=n-1;i>=0;i--){
//             maxRight[i] = maxR;
//             maxR = max(maxR, height[i]);
//         }

//         int res = 0;

//         for(int i=0;i<n;i++){
//             int curr = min(maxLeft[i], maxRight[i]) - height[i];
//             if(curr > 0) res += curr;
//         }

//         return res;
//     }
// };

int main(){
    Solution sol;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<sol.trap(height);
    return 0;
}