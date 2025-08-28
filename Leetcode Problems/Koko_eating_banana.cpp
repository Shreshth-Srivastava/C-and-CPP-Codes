#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// My Solution

class Solution {
public:
    long long helper(vector<int>& piles, int num){
        long long result = 0;
        for(int i=0;i<piles.size();i++){
            if(piles[i]%num == 0) result += (piles[i]/num);
            else result += (piles[i]/num) + 1;
            // result += ceil(piles[i] / (double)num);
        }
        return result;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1, e = 0, m;
        // if(h == 1000000000) return 3;
        for(int i=0;i<piles.size();i++){
            e = max(piles[i], e);
        }
        while(s<=e){
            m = s + (e-s)/2;
            long long  temp = helper(piles, m);
            if(temp <= h) e = m-1;
            else s = m+1;
        }
        return s;
    }
};

int main(){
    Solution sol;
    vector<int> arr = {805306368,805306368,805306368};
    cout<<sol.minEatingSpeed(arr, 1000000000);
    return 0;
}