#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Correct Solution

class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        int n=nums.size();

        vector<int> nums1(nums.begin(), nums.end());
        vector<int> nums2(nums.begin(), nums.end());
        int cnt1=0, cnt2=0;
        
        // Make all 1
        for(int i=0; i<n-1; i++) {
            if(nums1[i]==1) continue;
            else if(nums1[i]==-1 && nums1[i+1]==-1) {
                nums1[i]=1;
                nums1[i+1]=1;
                cnt1++;
                i++;
            }
            else if(nums1[i]==-1 && nums1[i+1]==1) {
                nums1[i]=1;
                nums1[i+1]=-1;
                cnt1++;
            }
        }
        if(cnt1<=k && nums1==vector<int>(n, 1)) return true;
            
        // Make all -1
        for(int i=0; i<n-1; i++) {
            if(nums2[i]==-1) continue;
            else if(nums2[i]==1 && nums2[i+1]==1) {
                nums2[i]=-1;
                nums2[i+1]=-1;
                cnt2++;
                i++;
            }
            else if(nums2[i]==1 && nums2[i+1]==-1) {
                nums2[i]=-1;
                nums2[i+1]=1;
                cnt2++;
            }
        }
        if(cnt2<=k && nums2==vector<int>(n, -1)) return true;
        
        return false;
    }
};

// My Solutions --> TLE

// class Solution {
// public:
//     bool canMakeEqual(vector<int>& nums, int k) {
//         if(nums.size() == 1) return true;

//         int pos = 0, neg = 0;
//         for(const auto& num:nums){
//             if(num == 1) pos++;
//             else neg++;
//         }

//         if(pos == 0 || neg == 0) return true;

//         int cnt1 = 0, cnt2 = 0, temp_pos = pos, temp_neg = neg, temp_k = k;

//         for(int i=0;i<nums.size()-1;++i){
//             if(pos == 0 || neg == 0) return true;
//             if(nums[i] == 1) continue;

//             nums[i] *= -1;
//             neg--;
//             pos++;

//             if(nums[i+1] == 1){
//                 pos--;
//                 neg++;
//             }
//             else{
//                 pos++;
//                 neg--;
//             }

//             nums[i+1] *= -1;
//             if(nums[i] == 1 && nums[i+1] == 1) i++;
//             k--;
//         }
    
//         if((pos == 0 || neg == 0) && k>=0) return true;

//         pos = temp_pos, neg = temp_neg, k = temp_k;

//         for(int i=0;i<nums.size()-1;++i){
//             if(pos == 0 || neg == 0) return true;
//             if(nums[i] == -1) continue;

//             nums[i] *= -1;
//             neg--;
//             pos++;

//             if(nums[i+1] == 1){
//                 pos--;
//                 neg++;
//             }
//             else{
//                 pos++;
//                 neg--;
//             }

//             nums[i+1] *= -1;
//             if(nums[i] == 1 && nums[i+1] == 1) i++;
//             k--;
//         } 

//         if((pos == 0 || neg == 0) && k>=0) return true;
        
//         return false;
//     }
// };

// class Solution {
// public:
//     bool canMakeEqual(vector<int>& nums, int k) {
//         if(nums.size() == 1) return true;

//         int pos = 0, neg = 0;
//         for(const auto& num:nums){
//             if(num == 1) pos++;
//             else neg++;
//         }

//         if(pos == 0 || neg == 0) return true;
        
//         return dfs(nums, k, -1, pos, neg);
//     }
// private:
//     bool dfs(vector<int>& nums, int& k, int curr, int& pos, int& neg){
//         if(k == 0){
//             // int pos = 0, neg = 0;
//             // for(const auto& num:nums){
//             //     if(num == 1) pos++;
//             //     else neg++;
//             // }

//             if(pos == 0 || neg == 0) return true;
//             else return false;
//         };

//         if(pos == 0 || neg == 0) return true;

//         for(int i=0;i<nums.size()-1;++i){
//             // vector<int> temp = nums;
//             if(i == curr) return false;
//             // temp[i] *= -1;
//             // temp[i+1] *= -1;
//             // if(dfs(temp, k-1, i)) return true;

//             int temp_pos = pos, temp_neg = neg;

//             if(nums[i] == 1){
//                 temp_pos--;
//                 temp_neg++;
//             }
//             else{
//                 temp_pos++;
//                 temp_neg--;
//             }

//             if(nums[i+1] == 1){
//                 temp_pos--;
//                 temp_neg++;
//             }
//             else{
//                 temp_pos++;
//                 temp_neg--;
//             }

//             nums[i] *= -1;
//             nums[i+1] *= -1;

//             if(dfs(nums, k-1, i, temp_pos, temp_neg)) return true;

//             nums[i] *= -1;
//             nums[i+1] *= -1;
//         }

//         return false;
//     }
// };

int main(){
    Solution sol;

    // vector<int> nums = {-1,1,-1};
    // cout<<sol.canMakeEqual(nums, 2);

    vector<int> nums = {1,-1,1,-1,1};
    cout<<sol.canMakeEqual(nums, 3);

    // vector<int> nums = {-1,-1,-1,1,1,1};
    // cout<<sol.canMakeEqual(nums, 5);

    // vector<int> nums = {-1,1};
    // cout<<sol.canMakeEqual(nums, 3);

    return 0;
}