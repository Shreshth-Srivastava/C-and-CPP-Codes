#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    string fractionAddition(string s){
        int num = 0, denom = 1;
        int i = 0, num2, denom2;
        bool negative;
        while(i < s.size()){
            num2 = 0, denom2 = 0;
            negative = false;
            if(s[i] == '-' || s[i] == '+'){
                if(s[i] == '-') negative = true;
                i++;
            }
            while(isdigit(s[i])){
                num2 = num2*10 + s[i] - '0';
                i++;
            }
            if(negative) num2 *= -1;
            i++;
            while(i<s.size() && isdigit(s[i])){
                denom2 = denom2*10 + s[i] - '0';
                i++;
            }
            num = num*denom2 + num2*denom;
            denom *= denom2;
        }
        int gcd = abs(GCD(num, denom));
        num /= gcd;
        denom /= gcd;
        return to_string(num)+'/'+to_string(denom);
    }
private:
    int GCD(int a, int b){
        if(a == 0) return b;
        return GCD(b%a, a);
    }
};

int main(){
    Solution sol;
    string str = "-5/2+10/3+7/9";
    cout<<sol.fractionAddition(str);
    return 0;
}