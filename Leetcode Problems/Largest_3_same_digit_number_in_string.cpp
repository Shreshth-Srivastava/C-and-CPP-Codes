#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// My Solution: Time Complexity --> O(N) ; Space Complexity --> O(1)

class Solution {
public:
    string largestGoodInteger(string num) {
        string res = "", curr = "";

        int n = num.size();

        for(int i=0;i<n-2;++i){
            if((num[i] == num[i+1]) && (num[i+1] == num[i+2])){
                curr = num[i];

                res = max(res, curr);
            }
        }
        
        curr = res;

        res.append(curr);
        res.append(curr);

        return res;
    }
};

int main(){
    Solution sol;

    cout<<sol.largestGoodInteger("6777133339");

    return 0;
}