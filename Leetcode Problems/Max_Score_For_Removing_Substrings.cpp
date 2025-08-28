#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// My Optimised Solution: Time Complexity --> O(N) ; Space Complexity --> O(N)

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char> stk1, stk2;
        int res = 0, val1 = x > y ? x : y, val2 = x > y ? y : x;
        char first = x > y ? 'a' : 'b', second = x > y ? 'b' : 'a';

        for(const auto& c: s){
            if(stk1.empty()){
                stk1.push(c);
                continue;
            }
            
            char temp = stk1.top();
            if(temp == first && c == second){
                res += val1;
                stk1.pop();
            }
            else
                stk1.push(c);
        }

        while(!stk1.empty()){
            char c = stk1.top();
            stk1.pop();

            if(stk2.empty()){
                stk2.push(c);
                continue;
            }
            
            char temp = stk2.top();
            if(temp == first && c == second){
                res += val2;
                stk2.pop();
            }
            else
                stk2.push(c);
        }

        return res;
    }
};

// My Solution: Time Complexity --> O(N) ; Space Complexity --> O(N)

/*class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char> stk;
        int res = 0, val1 = x > y ? x : y, val2 = x > y ? y : x;
        char first = x > y ? 'a' : 'b', second = x > y ? 'b' : 'a';

        for(const auto& c: s){
            if(stk.empty()){
                stk.push(c);
                continue;
            }
            
            char temp = stk.top();
            if(temp == first && c == second){
                res += val1;
                stk.pop();
            }
            else
                stk.push(c);
        }

        string s2 = "";
        while(!stk.empty()){
            s2.append(1, stk.top());
            stk.pop();
        }

        reverse(s2.begin(), s2.end());

        for(const auto& c: s2){
            if(stk.empty()){
                stk.push(c);
                continue;
            }
            
            char temp = stk.top();
            if(temp == second && c == first){
                res += val2;
                stk.pop();
            }
            else
                stk.push(c);
        }

        return res;
    }
};*/

int main(){
    Solution sol;

    string s = "aabbabkbbbfvybssbtaobaaaabataaadabbbmakgabbaoapbbbbobaabvqhbbzbbkapabaavbbeghacabamdpaaqbqabbjbababmbakbaabajabasaabbwabrbbaabbafubayaazbbbaababbaaha";
    cout<<sol.maximumGain(s, 1926, 4320);

    return 0;
}