#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

// My Solution: Time Complexity --> O(N^2) ; Space Complexity --> O(1)

class Solution {
public:
    string removeKdigits(string num, int k) {  // Called by value for testing here
        if(k == num.size()) return "0";

        for(int i=0;i<num.size()-1;){
            if(num[i]>num[i+1] && k>0){
                num.erase(i, 1);
                i = i>0 ? i-1 : 0;
                k--;
            }
            else{
                ++i;
            }
        }

        while(num.size() > 0 && k>0){
            num.erase(num.size()-1, 1);
            k--;
        }

        for(int i=0;i<num.size() && num.size() > 1;){
            if(num[i] != '0') break;
            num.erase(i,1);
        }

        return num.size() > 0 ? num : "0";
    }
};

// My Solution: Time Complexity --> O(N) ; Space Complexity --> O(N)

/*class Solution {
public:
    string removeKdigits(string& num, int k) {  // Call by value for testing here
        if(k == num.size()) return "0";

        int n = num.size();
        stack<char> stk;
        stk.push(num[0]);

        for(int i=1;i<n;++i){
            char curr = stk.top();

            while(!stk.empty() && num[i] < curr && k>0){
                stk.pop();
                k--;
                if(!stk.empty()) curr = stk.top();
            }
            
            stk.push(num[i]);
        }

        while(!stk.empty() && k>0){
            stk.pop();
            k--;
        }

        string res = "";

        while(!stk.empty()){
            char curr = stk.top();
            stk.pop();
            res.append(1, curr);
        }

        reverse(res.begin(), res.end());

        for(int i=0;i<res.size() && res.size()>1;){
            if(res[i] != '0') break;
            res.erase(i, 1);
        }

        return res == "" ? "0" : res;
    }
};*/

int main(){
    Solution sol;
    
    cout<<sol.removeKdigits("4132", 3);

    // cout<<sol.removeKdigits("9876", 2);

    // cout<<sol.removeKdigits("1432219", 3);

    // cout<<sol.removeKdigits("10200", 1);

    // cout<<sol.removeKdigits("33526221184202197273", 19);


    return 0;
}