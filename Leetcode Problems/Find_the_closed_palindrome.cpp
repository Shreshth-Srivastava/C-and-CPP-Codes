#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.size();
        int i = len % 2 == 0 ? len / 2 - 1 : len / 2;
        long firstHalf = stol(n.substr(0, i + 1));
        /*
        Generate possible palindromic candidates:
        1. Create a palindrome by mirroring the first half.
        2. Create a palindrome by mirroring the first half incremented by 1.
        3. Create a palindrome by mirroring the first half decremented by 1.
        4. Handle edge cases by considering palindromes of the form 999...
           and 100...001 (smallest and largest n-digit palindromes).
        */
        vector<long> possibilities;
        possibilities.push_back(halfToPalindrome(firstHalf, len % 2 == 0));
        possibilities.push_back(halfToPalindrome(firstHalf + 1, len % 2 == 0));
        possibilities.push_back(halfToPalindrome(firstHalf - 1, len % 2 == 0));
        possibilities.push_back((long)pow(10, len - 1) - 1);
        possibilities.push_back((long)pow(10, len) + 1);

        long diff = LONG_MAX, res = 0, nl = stol(n);
        for (auto cand : possibilities) {
            if (cand == nl) continue;
            if (abs(cand - nl) < diff) {
                diff = abs(cand - nl);
                res = cand;
            } else if (abs(cand - nl) == diff) {
                res = min(res, cand);
            }
        }

        return to_string(res);
    }

private:
    long halfToPalindrome(long left, bool even) {
        long res = left;
        if (!even) left = left / 10;
        while (left > 0) {
            res = res * 10 + left % 10;
            left /= 10;
        }
        return res;
    }
};

// Brute force approach for smaller values

/*class Solution {
public:
    string nearestPalindromic(string s) {
        int num = stoi(s);
        int l = left(num-1);
        int r = right(num+1);
        int diffl = num - l;
        int diffr = r - num;
        int res = (diffr>=diffl)?l:r;
        return to_string(res);
    }
private:
    bool check(string val){
        if(stoi(val) < 10) return true;
        int n = val.size();
        int i = 0, j = n-1;
        while(i<=j){
            if(val[i] != val[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int left(int num){
        string val = to_string(num);
        if(check(val)) return num;
        return left(num-1);
    }

    int right(int num){
        string val = to_string(num);
        if(check(val)) return num;
        return right(num+1);
    }
};
*/

int main(){
    Solution sol;
    string s = "1000";
    cout<<sol.nearestPalindromic(s);
    return 0;
}