#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Time Complexity --> O(m*n) ; Space Complexity --> O(m+n)

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";

        int n1 = num1.size(), n2 = num2.size();
        vector<int> res(n1+n2, 0);
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                int digit = (num1[i] - '0') * (num2[j] - '0');
                res[i+j] += digit;
                res[i+j+1] += res[i+j]/10;
                res[i+j] %= 10;
            }
        }

        stringstream result;
        int i = res.size() - 1;
        while(i>=0 && res[i] == 0) --i;
        while(i>=0){
            result << res[i--];
        }

        return result.str();
    }
};