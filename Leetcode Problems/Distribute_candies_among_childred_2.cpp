#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Much Cleaner Solution
/*class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long res = 0;
        for (int i = 0; i <= min(limit, n); i++) {
            if (n - i <= 2 * limit)
                res += min(n - i, limit) - max(0, n - i - limit) + 1;
        }
        return res;
    }
};*/

// My Solution: Time Complexity --> O(min(n, Limit)) ; Space Complexity --> O(1)

class Solution {
public:
    long long distributeCandies(int n, int limit) {
        int num = min(n,limit);
        long long res = 0;

        for(int i = 0;i<=num;++i){
            // Calculation for first child

            int remain = n - i;
            
            if(remain > 2*limit) continue;
            if(remain == 0 || remain == 2*limit){
                res++;
                continue;
            };
            
            // Calculation for second child

            int temp = remain - limit;
            temp = max(0, temp);

            // Calculation for third child

            remain = min(remain, limit);
            res += remain - temp + 1;
        }

        return res;
    }
};

int main(){
    Solution sol;
    cout<<sol.distributeCandies(10, 7);
    // cout<<sol.distributeCandies(3, 5);
    // cout<<sol.distributeCandies(5, 2);
    return 0;
}