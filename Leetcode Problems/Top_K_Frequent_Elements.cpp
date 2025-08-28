#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        vector<vector<int>> buckets(n+1);
        for(auto it = m.begin();it != m.end();++it){
            buckets[it->second].push_back(it->first);
        }
        vector<int> result;
        for(int j = n;j >= 0; j--){
            if(result.size() >= k) break;
            if(!buckets[j].empty()){
                result.insert(result.end(),buckets[j].begin(),buckets[j].end());
            }
        }
        return result;
    }
};

// By Using pairs
// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) 
//     {
//         vector<int>ans;
//         map<int,int>mp;
//         for(int i=0;i<nums.size();i++)
//             mp[nums[i]]++;
//         vector<pair<int,int>>v;
//         for(auto it : mp )
//             v.push_back(make_pair(it.second,it.first));
//         sort(v.rbegin(),v.rend());
//         for(int i=0;i<v.size() && k!=0 ;i++)
//         {
//             ans.push_back(v[i].second);
//             k--;
//         }       
//         return ans; 
//     }
// };

//Another Approach
//  vector<int> topKFrequent(vector<int>& nums, int k) {
//     std::unordered_map<int, int> freq;
//     std::vector<int> ret;
//     ret.reserve(nums.size());
//     for (auto n : nums) {
//       if (1 == ++freq[n]) {
//         // Count the frequency for each int, storing each new int as we go
//         ret.push_back(n);
//       }
//     }

//     // Piviot around the kth element using custom compare. Elements are not sorted, just
//     // reordered such that all elements in the range [0, k] are greater than those in [k + 1, n)
//     // This is an (average) O(n) operation
//     std::nth_element(ret.begin(), ret.begin() + k - 1, ret.end(), [&freq] (int l, int r) -> bool {
//         return freq[l] > freq[r];
//       });
//     ret.resize(k);
//     return ret;
//   }