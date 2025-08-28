#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos(31, -1);
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; --i) {
            int j = i;
            for (int bit = 0; bit < 31; ++bit) {
                if (!(nums[i] & (1 << bit))) {
                    if (pos[bit] != -1) {
                        j = max(j, pos[bit]);
                    }
                } else {
                    pos[bit] = i;
                }
            }
            ans[i] = j - i + 1;
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> smallestSubarrays(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> res(n, 1), suffix(n+1, 0);

//         for(int i=n-1;i>=0;--i){
//             suffix[i] = suffix[i+1] | nums[i];
//             cout<<"Suffix["<<i<<"] = "<<suffix[i]<<endl;
//         }

//         int temp = 0;
//         for(int i=0;i<n-1;++i){
//             cout<<"For Element "<<i+1<<endl;
//             for(int j=i;j<n;++j){
//                 temp |= nums[j];
//                 cout<<"Temp:  "<<temp<<endl;
//                 if(temp == suffix[j+1] || suffix[j+1] == 0){
//                     res[i] = j - i + 1;
//                     temp = 0;
//                     break;
//                 }
//             }
//         }

//         return res;
//     }
// };