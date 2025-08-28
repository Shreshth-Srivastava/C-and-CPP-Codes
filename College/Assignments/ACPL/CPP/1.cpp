#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    void find_absent_digits(string mobile) {
        set<char> all_digits = {'0','1','2','3','4','5','6','7','8','9'};
        for (char c : mobile) all_digits.erase(c);
        if(!all_digits.empty()) for (char d : all_digits) cout << d << " ";
        else cout<<"No absent digits";
    }
};

int main(){
    Solution sol;
    string str;
    cout<<"Enter mobile number: ";
    cin>>str;
    if(str.size() != 10){
        cout<<"Invalid mobile number";
        return 0;
    }
    sol.find_absent_digits(str);
    return 0;
}