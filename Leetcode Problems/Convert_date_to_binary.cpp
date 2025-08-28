#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

// Cleaner Code
/*class Solution {
private:
    string toBinary(int num) {
        string res;
        while (num > 0) {
            res = char('0' + (num % 2)) + res;
            num /= 2;
        }
        return res.empty() ? "0" : res;
    }
public:
    string convertDateToBinary(string& date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
    
        return toBinary(year) + "-" + toBinary(month) + "-" + toBinary(day);
    }
};
*/

// My Solution: Time Complexity --> O(1) ; Space Complexity --> O(1)

class Solution {
public:
    string convertDateToBinary(string s) {
        string year = "", month = "", date = "";

        for(int i=0;i<4;++i){
            year.append(1, s[i]);
        }

        for(int i=5;i<7;++i){
            month.append(1, s[i]);
        }

        for(int i=8;i<10;++i){
            date.append(1, s[i]);
        }

        string res = "";

        res.append(toBinary(stoi(year)));
        res.append(1, '-');

        res.append(toBinary(stoi(month)));
        res.append(1, '-');

        res.append(toBinary(stoi(date)));

        return res;
    }
private:
    string toBinary(int num){
        int i = 0;
        string res = "";

        while(num >= 1){
            char temp;
            if((pow(10,i) * (num%2)) == 0){
                temp = '0';
            }
            else{
                temp = '1';
            }
            res.append(1, temp);
            ++i;
            num /= 2;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

int main(){
    Solution sol;
    cout<<sol.convertDateToBinary("2080-02-29");
    return 0;
}