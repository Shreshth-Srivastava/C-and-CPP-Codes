#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Bit Manipulation: Time Complexity --> O(N) ; Space Complexity --> O(1)
Description: Observe the results in bits, we notice that the last N-1 bits are all zeroes, where N is the number of inputs. So we just have to find the most significant bits.
*/
// Optimised Backtracking: Time Complexity --> O(2^N) ; Space Complexity --> O(N)

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return dfs(0, 0, nums);
    }
private:
    int dfs(int index, int currXOR, vector<int>& nums){
        // Base Condition
        if(index == nums.size()){
            return currXOR;
        }
        
        // Skip the current value
        int notTake = dfs(index+1, currXOR, nums);

        // Take the current value
        int take = dfs(index+1, currXOR^nums[index], nums);

        int result = take + notTake;
        return result;
    }
};

// My Solution: Time Complexity --> O(N*2^N) ; Space Complexity --> O(N)

// class Solution {
// public:
//     int subsetXORSum(vector<int>& nums) {
//         vector<int> curr;
//         return dfs(0, curr, nums);
//     }
// private:
//     int dfs(int index, vector<int>& curr, vector<int>& nums){
//         // Base Condition
//         if(index == nums.size()){
//             if(curr.empty()){
//                 return 0;
//             }
//             else{
//                 int temp = curr[0];
//                 for(int i=1;i<curr.size();i++){
//                     temp ^= curr[i];
//                 }
//                 return temp;
//             }
//         }
        
//         // Skip the current value
//         int notTake = dfs(index+1, curr, nums);

//         // Take the current value
//         curr.push_back(nums[index]);
//         int take = dfs(index+1, curr, nums);
//         curr.pop_back();

//         int result = take + notTake;
//         return result;
//     }
// };

int main(){
    Solution sol;
    vector<int> nums = {3,4,5,6,7,8};
    cout<<sol.subsetXORSum(nums);
    return 0;
}