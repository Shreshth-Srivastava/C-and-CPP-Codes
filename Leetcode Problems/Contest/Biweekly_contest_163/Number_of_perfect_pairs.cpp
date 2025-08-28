#include<iostream>
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

// TLE

class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        ll res = 0;
        int n = nums.size();
        priority_queue<int> pq;
        vector<int> temp;

        for(int i = 0;i<n;++i){
            int b = abs(nums[i]);

            while(!pq.empty()){
                int a = pq.top();
                pq.pop();
                
                int minVal = min(abs(a - b), abs(a + b));
                int maxVal = max(abs(a - b), abs(a + b));

                if(minVal <= min(a,b) && maxVal >= max(a,b)){
                    cout<<"a: "<<a<<", b: "<<b<<endl;
                    res++;
                }
                temp.push_back(a);
            }

            for(auto elem: temp){
                pq.push(elem);
            }
            temp.clear();

            pq.push(b);
        }
        
        return res;
    }
};

int main(){
    Solution sol;

    vector<int> nums = {-3,2,-1,4};

    cout<<sol.perfectPairs(nums);

    return 0;
}