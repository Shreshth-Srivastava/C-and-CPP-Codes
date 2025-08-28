#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Better Solution

class Solution {
public:
    int getLucky(string s, int k) {
        int res = 0, pos;
        for(int i=0;i<s.size();i++){
            pos = s[i] - 'a' + 1;
            while(pos > 0){
                res += pos%10;
                pos /= 10;
            }
        }
        while(k>1){
            res = helper(res);
            k--;
        }
        return res;
    }
private:
    int helper(int n){
        int res = 0;
        while(n>0){
            res += n%10;
            n /= 10;
        }
        return res;
    }
};

// My Solution

/*
class Solution {
public:
    int getLucky(string s, int k) {
        string temp = "";
        for(int i=0;i<s.size();i++) temp += to_string(s[i] - 'a' + 1);
        int res = 0;
        for(int j=0;j<temp.size();j++) res += temp[j] - '0';
        while(k>1){
            res = helper(res);
            k--;
        }
        return res;
    }
private:
    int helper(int n){
        int res = 0;
        while(n>0){
            res += n%10;
            n /= 10;
        }
        return res;
    }
};
*/