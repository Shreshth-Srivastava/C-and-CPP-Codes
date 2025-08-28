#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// My Solution: Time Complexity --> O(N) ; Space Compelxity --> O(N)

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> m;

        for(const auto& num: deck){
            m[num]++;
        }

        int prev = -1;

        for(const auto& num: m){
            if(prev == -1) prev = num.second;
            else{
                prev = gcd(prev, num.second);
            }
            if(prev < 2) return false;
        }

        return true;
    }
private:
    int gcd(int a, int b){
        if(a<b) swap(a,b);
        while(b != 0){
            int temp = a%b;
            if(temp == 0) return b;
            a = b;
            b = temp;
        }
        return a;
    }
};

int main(){
    Solution sol;
    // vector<int> deck = {1,2};
    // vector<int> deck = {1};
    // vector<int> deck = {1,2,2};
    // vector<int> deck = {1,2,3,4,4,3,2,1};
    // vector<int> deck = {1,1,2,2,2,2};
    vector<int> deck = {1,1,1,1,2,2,2,2,2,2};
    cout<<sol.hasGroupsSizeX(deck);
    return 0;
}