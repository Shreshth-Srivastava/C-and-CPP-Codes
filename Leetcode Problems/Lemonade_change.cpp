#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0, tens = 0;
        for(int i=0;i<bills.size();++i){
            if(bills[i] == 10){
                if(fives>0) --fives;
                else return false;
                ++tens;
            }
            else if(bills[i] == 20){
                if(tens > 0 && fives>0){
                    --tens;
                    --fives;
                }
                else if(fives >= 3){
                    fives -= 3;
                }
                else return false;
            }
            else ++fives;
        }
        return true;
    }
};

int main(){
    Solution sol;
    vector<int> bills = {5,5,5,10,20};
    cout<<sol.lemonadeChange(bills);
    return 0;
}