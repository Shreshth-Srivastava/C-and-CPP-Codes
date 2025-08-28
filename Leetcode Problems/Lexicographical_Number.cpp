#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> lexicographicalNumbers;
        int currentNumber = 1;

        // Generate numbers from 1 to n
        for (int i = 0; i < n; ++i) {
            lexicographicalNumbers.push_back(currentNumber);

            // If multiplying the current number by 10 is within the limit, do
            // it
            if (currentNumber * 10 <= n) {
                currentNumber *= 10;
            } else {
                // Adjust the current number by moving up one digit
                while (currentNumber % 10 == 9 || currentNumber >= n) {
                    currentNumber /= 10;  // Remove the last digit
                }
                currentNumber += 1;  // Increment the number
            }
        }

        return lexicographicalNumbers;
    }
};

// Brute Force Approach
/*
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        
        for(int i=1;i<=min(9, n);++i){
            res.push_back(i);
            for(int j=i*10;j<=min(i*10+9, n);++j){
                res.push_back(j);
                for(int k=j*10;k<=min(j*10+9, n);++k){
                    res.push_back(k);
                    for(int l=k*10;l<=min(k*10+9, n);++l){
                        res.push_back(l);
                        for(int m=l*10;m<=min(l*10+9, n);++m){
                            res.push_back(m);
                        }
                    }
                }
            }
        }

        return res;
    }
};
*/

int main(){
    Solution sol;

    // sol.lexicalOrder(13);

    sol.lexicalOrder(34);

    return 0;
}