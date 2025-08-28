#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast","unroll-loops","-ffast-math","march=native")

typedef long long ll;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        ll l = 0, res = LLONG_MIN, r = 0, bsk1 = -1, bsk2 = -1, n = fruits.size();
        ll bsk1Last = -1, bsk2Last = -1;   

        while(r < n){
            if(r < n && bsk1 == -1){
                bsk1 = fruits[r];   
            }

            while(r < n && fruits[r] == bsk1){
                bsk1Last = r;
                r++;
            }

            if(r < n && bsk2 == -1){
                bsk2 = fruits[r];
            }

            while(r < n && fruits[r] == bsk2){
                bsk2Last = r;
                r++;
            }

            if(r < n && fruits[r] != bsk1 && fruits[r] != bsk2){
                res = max(res, max(bsk1Last, bsk2Last) - l + 1);

                if(bsk1 == fruits[r-1]){
                    l = bsk2Last + 1;
                    bsk2 = fruits[r];
                    bsk2Last = r;
                }
                else{
                    l = bsk1Last + 1;
                    bsk1 = fruits[r];
                    bsk1Last = r;
                }
            }

            res = max(res, r < n ? r - l + 1 : r - l);
        }

        return res;
    }
};

int main(){
    Solution sol;

    // vector<int> fruits = {3,3,3,1,2,1,1,2,3,3,4};
    vector<int> fruits = {3,3,3,1,2,1,2,1,2,3,1,1,2,2,1,3,3,2,2,3,1,2};
    // vector<int> fruits = {1,2,3,2,2,3,3,2,1,1,2,3,3,2,2,1,1,3};

    cout<<sol.totalFruit(fruits);

    return 0;
}