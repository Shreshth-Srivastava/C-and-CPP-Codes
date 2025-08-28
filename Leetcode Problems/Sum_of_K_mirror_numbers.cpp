#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

class Solution {
public:
    long long kMirror(int k, int n) {
        long long res = 0;
        int num = 1;
        while(n>0){
            if(convert(num, k) != ""){
                res += num;
                n--;
            }
            num++;
        }

        return res;
    }
private:
    string convert(int num, int k){
        int i = 0;
        string res = "";

        while(num >= 1){
            string temp;
            temp = to_string((int)(num%k));
            res.append(temp);
            ++i;
            num /= 2;
        }

        reverse(res.begin(), res.end());
        if(isPalindrome(res))
            return res;
        
        return "";
    }

    bool isPalindrome(string& s){
        int r = s.size() - 1;
        for(int l=0;l<s.size()/2;++l){
            if(s[l] != s[r])
                return false;
            r--;
        }
        return true;
    }
};

int main(){
    Solution sol;

    cout<<sol.kMirror(2, 5);

    return 0;
}