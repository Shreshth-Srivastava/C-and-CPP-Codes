#include<iostream>
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        ll initialProfit = 0;

        for(int i=0;i<n;++i)
                initialProfit += (ll)(strategy[i]*prices[i]);

        int half = k/2;
        ll currentWinChange = 0;

        for(int i=0;i<half;++i)
            currentWinChange -= (ll)(strategy[i]*prices[i]);

        for(int i=half;i<k;++i)
            currentWinChange += (1LL - strategy[i]) * prices[i];

        ll maxChange = currentWinChange;

        for(int i = 1;i <= n-k;++i){
            int prevIdx = i-1, pivotIdx = i + half - 1, newIdx = i + k - 1;

            currentWinChange += (ll)(strategy[prevIdx])*prices[prevIdx];
            currentWinChange -= prices[pivotIdx];
            currentWinChange += (1LL - strategy[newIdx])*prices[newIdx];

            maxChange = max(maxChange, currentWinChange);
        }

        return initialProfit + max(0LL,maxChange);
    }
};

int main(){
    Solution sol;

    vector<int> prices = {4,2,8};
    vector<int> strategy = {-1,0,1};
    int k = 2;
    cout<<sol.maxProfit(prices, strategy, k);

    return 0;
}