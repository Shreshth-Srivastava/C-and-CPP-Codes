#include<iostream>
#include<bits/stdc++.h>
// #include<vector>
// #include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        if(n < 3) return result;
        sort(nums.begin(),nums.end());
        for(int i = 0;i < n-2;i++){
            if(nums[i] > 0) break;
            if(i > 0 && nums[i-1] == nums[i]) continue;
            int j = i+1, k = n-1;
            while(j < k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum > 0){
                    k--;
                }
                else if(sum < 0){
                    j++;
                }
                else{
                    result.push_back({nums[i],nums[j],nums[k]});
                    while(j < k && nums[j+1] == nums[j]){
                        j++;
                    }
                    j++;
                    while(j < k && nums[k-1] == nums[k]){
                        k--;
                    }
                    k--;
                }
            }
        }
        return result;
    }
};

int main(){
    vector<int> nums;
    Solution sol;
    nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> result = sol.threeSum(nums);
    for (int i = 0; i < result.size(); i++)
    {
        cout<<"{ ";
        for (int j = 0; j < result[i].size(); j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<"}"<<endl;
        
    }
    
    return 0;
}