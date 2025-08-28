#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        int profit = 0, l = 0, r = 1;
        for(int i=0;i<prices.size() - 1;i++){
            if(prices[l] >= prices[r]){
                l=r;
            }
            else{
                int current = prices[r] - prices[l];
                profit = max(profit,current);   
            }
            r++;
        }
        return profit;
    }
};

int main(){
    Solution sol;
    vector<int> arr = {1,2,4,2,5,7,2,4,9,0,9};
    int profit = sol.maxProfit(arr);
    cout<<profit<<endl;
    return 0;
}