#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int res = 0, temp;
        for(int i = 0;num>0;i++){
            temp = num&1;
            if(!temp) res += pow(2,i);
            num >>= 1;
        }
        return res;
    }
};