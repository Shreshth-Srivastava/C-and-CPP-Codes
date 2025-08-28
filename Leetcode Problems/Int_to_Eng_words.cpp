#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Better Solution, const char[] does not allow concatenation thorugh '+' operator, where C++ string does 

class Solution {
public:

    string ones[20] = {"", " One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine", " Ten", " Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen", " Sixteen", " Seventeen", " Eighteen", " Nineteen"};
    string tens[10] = {"", " Ten", " Twenty", " Thirty", " Forty", " Fifty", " Sixty", " Seventy", " Eighty", " Ninety"};
    string thousands[4] = {"", " Thousand", " Million", " Billion"};
    
    string helper(int n) {
        if (n < 20) 
            return ones[n];
        if (n < 100) 
            return tens[n / 10] + helper(n % 10);
        if (n < 1000) 
            return helper(n / 100) + " Hundred" + helper(n % 100);
        for (int i = 3; i >= 0; i--) {
            if (n >= pow(1000, i)) {
                return helper(n / pow(1000, i)) + thousands[i] + helper(n % (int)pow(1000, i));
            }
        }
        return "";
    }

    string numberToWords(int num) {
        // edge case
        if (num == 0) 
            return "Zero";
        return helper(num).substr(1);
    }
};

// My Solution

/*class Solution {
public:
    string helper(unordered_map<int, string> m ,int num){
        string result = "";
        if(num<100){
            int Ten = num%100;
            if(Ten > 20){
                int temp = Ten/10;
                temp *= 10;
                result.append(m[temp]);
                temp = Ten%10;
                if(temp != 0){
                    result.append(" ");
                    result.append(m[temp]);
                }
            }
            else if(Ten == 0) return result;
            else{
                result.append(m[Ten]);
            }
        }
        else {
            int Hundred = num/100;
            result.append(m[Hundred]);
            result.append(" Hundred");
            int Ten = num%100;
            if(Ten > 20){
                result.append(" ");
                int temp = Ten/10;
                temp *= 10;
                result.append(m[temp]);
                temp = Ten%10;
                if(temp != 0){
                    result.append(" ");
                    result.append(m[temp]);
                }
            }
            else{
                if(Ten != 0){
                    result.append(" ");
                    result.append(m[Ten]);
                }
            }
        }
        return result;
    }

    string numberToWords(int num) {
        unordered_map<int, string> m = {{0 , "Zero"},
        {1 , "One"},
        {2 , "Two"},
        {3 , "Three"},
        {4 , "Four"},
        {5 , "Five"},
        {6 , "Six"},
        {7 , "Seven"},
        {8 , "Eight"},
        {9 , "Nine"},
        {10 , "Ten"},
        {11 , "Eleven"},
        {12 , "Twelve"},
        {13 , "Thirteen"},
        {14 , "Fourteen"},
        {15 , "Fifteen"},
        {16 , "Sixteen"},
        {17 , "Seventeen"},
        {18 , "Eighteen"},
        {19 , "Nineteen"},
        {20 , "Twenty"},
        {30 , "Thirty"},
        {40 , "Forty"},
        {50 , "Fifty"},
        {60 , "Sixty"},
        {70 , "Seventy"},
        {80 , "Eighty"},
        {90 , "Ninety"},
        {100 , "Hundred"},
        {1000 , "Thousand"},
        {1000000 , "Million"},
        {1000000000 , "Billion"}
        };
        int n = 0, temp = num;
        string result = "";
        while(temp > 0){ 
            n++;
            temp /= 10;
        }
        int j;
        if(n%3 > 0){
            j = n/3;
        }
        else if(n == 0){
            result.append(m[0]);
            return result;
        }
        else j = n/3 - 1;
        int k = j;
        for(j;j>=0;j--){
            if(j != 0){
                string str = helper(m, num/pow(1000, j));
                if(str != ""){
                    if(j != k) result.append(" ");
                    result.append(str);
                    result.append(" ");
                    result.append(m[pow(1000, j)]);
                }
                num %= (int)pow(1000, j);
            }
            else{
                string str = helper(m, num%1000);
                if(str != "" && j != k) result.append(" ");
                result.append(str);
            }
        }
        return result;
    }
};*/

int main(){
    Solution sol;
    cout<<sol.numberToWords(123);
    return 0;
}