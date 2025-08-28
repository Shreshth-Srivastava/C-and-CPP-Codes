#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Better Solution

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> count(201, 0);
        for (int num : nums) {
            count[num + 100]++;
        }
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (count[a + 100] == count[b + 100])
                return a > b;
            return count[a + 100] < count[b + 100];
        });
        return nums;
    }
};

// My Solution

/*class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<vector<int>> buckets(nums.size()+1);
        for (auto it = mp.begin(); it != mp.end(); it++) {
            buckets[it->second].push_back(it->first);
        }
        for(int i=0;i<nums.size();i++){
            if(!buckets[i].empty()) sort(buckets[i].begin(), buckets[i].end(), greater<int>());
        }
        vector<int> answer(nums.size());
        int index = 0;
        for(int j=0;j<buckets.size();j++){
            if (!buckets[j].empty()){
                for(auto it:buckets[j]){
                    for(int k=0;k<j;k++){
                        answer[index] = it;
                        index++;
                    }
                }
            }
        }
        return answer;
    }
};*/

int main(){
    Solution sol;
    vector<int> nums = {-3};
    vector<int> answer = sol.frequencySort(nums);
    for(auto it:answer){
        cout<<it<<endl;
    }
    return 0;
}