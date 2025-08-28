#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;

// My Solution: Time Complexity --> O(N^3) ; Space Complexity --> O(N^2)

class Solution {
public:
    long long sumOfLargestPrimes(string str) {
        set<long long, greater<long long>> s;
        long long res = 0;
        for(int i=0;i<str.size();i++){
            int temp = str[i] - '0';
            if(temp == 0) continue;
            string curr = "";
            curr += str[i];
            if(isPrime(temp)) s.insert(temp);
            for(int j=i+1;j<str.size();j++){
                curr += str[j];
                long long num = stoll(curr);
                if(isPrime(num)) s.insert(num);
            }
        }
        if(s.size() < 3){
            for(const auto& num: s){
                res += num;
            }
        }
        else{
            int k = 0;
            for(const auto& num: s){
                res += num;
                k++;
                if(k == 3) break;
            }
        }
        return res;
    }
private:
    bool isPrime(long long num){
        if(num == 1) return false;
        if(num <= 3) return true;
        for(int i=2;i<=sqrt(num);i++){
            if(num%i == 0) return false;
        }
        return true;
    }
};

int main(){
    Solution sol;
    // string s = "12234";
    // string s = "111";
    // string s = "6735992919";
    string s = "6357501617";
    cout<<sol.sumOfLargestPrimes(s);
    return 0;
}