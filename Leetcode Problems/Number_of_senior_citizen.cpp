#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        int age;
        for(int i=0;i<details.size();i++){
            age = (int)(details[i][11] - '0')*10 + (int)(details[i][12] - '0');
            if(age > 60) count++;
        }
        return count;
    }
};

int main(){
    Solution sol;
    vector<string> details = {"9751302862F0693","3888560693F7262","5485983835F0649","2580974299F6042","9976672161M6561","0234451011F8013","4294552179O6482"};
    sol.countSeniors(details);
    return 0;
}