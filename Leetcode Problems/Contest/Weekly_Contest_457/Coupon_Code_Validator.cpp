#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

// My Solution: Time Complexity --> O(N*logN*L) ; Space Complexity --> O(N*L) where L is the size of the string "code"

class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = isActive.size();
        vector<vector<string>> arr(4);
        vector<string> res;

        for(int i=0;i<n;++i){
            
            if(!isActive[i])
                continue;
            
            if(!checkCategory(businessLine[i]))
                continue;
            
            if(!checkCode(code[i]))
                continue;

            int idx = 0;

            if(businessLine[i] == "electronics")
                idx = 0;
            if(businessLine[i] == "grocery")
                idx = 1;
            if(businessLine[i] == "pharmacy")
                idx = 2;
            if(businessLine[i] == "restaurant")
                idx = 3;

            arr[idx].push_back(code[i]);
        }

        for(auto& val: arr){
            sort(val.begin(), val.end());
            for(const auto& s: val){
                res.push_back(s);
            }
        }


        return res;
    }
private:
    bool checkCategory(string& s){
        string cat1 = "electronics", cat2 = "grocery", cat3 = "pharmacy", cat4 = "restaurant";
        if(s == cat1 || s == cat2 || s == cat3 || s == cat4)
            return true;

        return false;
    }

    bool checkCode(string& s){
        if(s.size() == 0)
            return false;
        
        for(const auto& c: s){
            if(!checkChar(c)){
                return false;
            }
        }

        return true;
    }

    bool checkChar(char c){
        if(c >= 'a' && c <= 'z')
            return true;

        if(c >= 'A' && c <= 'Z')
            return true;

        if(c >= '0' && c <= '9')
            return true;

        if(c == '_')
            return true;

        return false;
    }
};

int main(){
    Solution sol;

    vector<string> code = {"SAVE20","","PHARMA5","SAVE@20"};
    vector<string> businessLine = {"restaurant","grocery","pharmacy","restaurant"};
    vector<bool> isActive = {true,true,true,true};

    cout<<"Test"<<endl;

    sol.validateCoupons(code, businessLine, isActive);

    return 0;
}