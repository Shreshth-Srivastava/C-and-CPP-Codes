#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Different Approach: Time Complexity --> O(N*log(N)) ; Space Complexity --> O(N)


class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<bool> isPrime(n, true);
        isPrime[0] = false;
        if (n > 1) isPrime[1] = false;
        for (int i = 2; i * i < n; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        long long s1 = 0, s2 = 0;
        for (int i = 0; i < n; ++i) {
            if (isPrime[i]) {
                s1 += nums[i];
            } else {
                s2 += nums[i];
            }
        }

        return abs(s1 - s2);
    }
};

// My Solution: Time Complexity --> O(N*Sqrt(N)) ; Space Complexity --> O(1)

/*class Solution {
public:
    long long splitArray(vector<int>& nums) {
        long long A = 0, B = 0;

        for(int i=0;i<nums.size();++i){
            if(isPrime(i)){
                A += nums[i];
            }
            else{
                B += nums[i];
            }
        }

        return (long long)abs(A - B);
    }
private:
    bool isPrime(int a){
        if(a == 1 || a == 0) return false;
        for(int i = 2;i<=sqrt(a);i++){
            if(a%i == 0)
                return false;
        }
        return true;
    }
};*/