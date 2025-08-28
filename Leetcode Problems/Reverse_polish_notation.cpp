#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(stack<int>& stk, string ch){
        int first = stk.top();
        stk.pop();
        int second = stk.top();
        stk.pop();
        if(ch == "+") return first+second;
        else if(ch == "-") return second-first;
        else if(ch == "*") return first*second;
        else return second/first;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int temp = helper(stk, tokens[i]);
                stk.push(temp);
            }
            else{
                stk.push(stoi(tokens[i]));
            }
        }
        return stk.top();
    }
};

int main(){
    Solution sol;
    vector<string> tokens = {"4","13","5","/","+"};
    sol.evalRPN(tokens);
    return 0;
}