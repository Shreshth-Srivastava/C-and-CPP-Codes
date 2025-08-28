#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MX = 1e5;

long long fact[MX];
long long inv_fact[MX];

class Solution {
private:
    long long qpow(long long x, int n) {
        long long res = 1;
        while (n) {
            if (n & 1) {
                res = res * x % MOD;
            }
            x = x * x % MOD;
            n >>= 1;
        }
        return res;
    }

    long long comb(int n, int m) {
        return fact[n] * inv_fact[m] % MOD * inv_fact[n - m] % MOD;
    }
    void init() {
        if (fact[0]) {
            return;
        }
        fact[0] = 1;
        for (int i = 1; i < MX; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }

        inv_fact[MX - 1] = qpow(fact[MX - 1], MOD - 2);
        for (int i = MX - 1; i; i--) {
            inv_fact[i - 1] = inv_fact[i] * i % MOD;
        }
    }
};

// Alternate Code
/*#define int long long

const int MOD = 1e9 + 7;

int mod(int a, int m = MOD){
    return a%m;
}

template <class T> class Math{
public:
    vector<T> fact, invfact;
    Math(){}
    Math(int n){
        fact.resize(n);
        invfact.resize(n);
        fact[0] = invfact[0] = 1;
        for(int i = 1;i<n;++i){
            fact[i] = mod(i*fact[i-1]);
            invfact[i] = modinv(fact[i]);
        }
    }
    T modinv(T x, T m = MOD){
        return expo(x, m-2, m);
    }
    T expo(T base, T exp, T m = MOD){
        T res = 1;
        while(exp){
            if(exp & 1){
                res = mod(res*base, m);
            }
            base = mod(base*base,m);
            exp >>= 1;
        }
        return res;
    }
    T choose(T n, T k){
        if(k < 0 || k > n)
            return 0;
        T ans = fact[n];
        ans = mod(ans*invfact[n-k]);
        ans = mod(ans*invfact[k]);
        return ans;
    }
};

signed main(){
    Math<int> m(1e6+1);
    cout<< m.choose(10,2)<<"\n";
}*/