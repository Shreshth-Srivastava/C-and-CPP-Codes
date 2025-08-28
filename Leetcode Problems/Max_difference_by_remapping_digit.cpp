#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;

// Editorial Solution --> Same Approach --> Cleaner Code
/*
class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string t = s;
        size_t pos = s.find_first_not_of('9');
        if (pos != string::npos) {
            char a = s[pos];
            replace(s.begin(), s.end(), a, '9');
        }
        char b = t[0];
        replace(t.begin(), t.end(), b, '0');
        return stoi(s) - stoi(t);
    }
};
*/

// My Solution: Time Complexity --> O(D) or O(log10(num)) ; Space Complexity --> O(D) or O(log10(num))

class Solution {
public:
    int minMaxDifference(int num) {
        string temp1 = to_string(num);
        string temp2 = temp1;

        char a;

        for(const auto& elem:temp1){
            if(elem != '9'){
                a = elem;
                break;
            }
        }


        for(auto& elem: temp1){
            if(elem == a){
                elem = '9';
            }
        }

        int maxNum = stoi(temp1);

        for(const auto& elem:temp2){
            if(elem != '0'){
                a = elem;
                break;
            }
        }

        for(auto& elem: temp2){
            if(elem == a){
                elem = '0';
            }
        }

        int minNum = stoi(temp2);

        return maxNum-minNum;
    }
};

int main(){
    Solution sol;

    // cout<<sol.minMaxDifference(1);
    // cout<<sol.minMaxDifference(11891);
    // cout<<sol.minMaxDifference(90);

    return 0;
}