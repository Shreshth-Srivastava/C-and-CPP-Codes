#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long

// My Soluton: Time Complexity --> O(logN) ; Space Complexity --> O(1)

class Solution {
private:
    const int MOD = 1e9 + 7;

    ll qpow(ll x, ll n) {
        ll res = 1;
        while (n) {
            if (n & 1) {
                res = res * x % MOD;
            }
            x = x * x % MOD;
            n >>= 1;
        }
        return res;
    }

public:
    int countGoodNumbers(ll n) {
        ll even_pos = (n+1)>>1, odd_pos = n - even_pos;
        
        return (qpow(5, even_pos) * qpow(4, odd_pos)) % MOD;
    }
};

int main(){
    Solution sol;

    cout<<sol.countGoodNumbers(50);

    return 0;
}
