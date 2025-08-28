#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// My Solution (Space Optimised): Time Complexity --> O(N) ; Space Complexity --> O(N)

class Solution {
public:
    int candy(vector<int>& ratings) {
        int res = 0, n = ratings.size();
        vector<int> temp(n, 1);

        for(int i=1;i<n;++i){
            if(ratings[i] > ratings[i-1]){
                temp[i] = temp[i-1]+1;
            }
        }

        for(int i=n-2;i>=0;--i){
            if(ratings[i] > ratings[i+1]){
                temp[i] = max(temp[i+1]+1, temp[i]);
            }
        }
        
        for(int i=0;i<n;++i){
            res += temp[i];
        }

        return res;
    }
};

// My Solution: Time Compelxity --> O(N) ; Space Complexity --> O(N)

// class Solution {
// public:
//     int candy(vector<int>& ratings) {
//         int res = 0, n = ratings.size();
//         vector<int> prefix(n, 1);
//         vector<int> suffix(n, 1);

//         for(int i=1;i<n;++i){
//             if(ratings[i] > ratings[i-1]){
//                 prefix[i] = prefix[i-1]+1;
//             }
//         }

//         for(int i=n-2;i>=0;--i){
//             if(ratings[i] > ratings[i+1]){
//                 suffix[i] = suffix[i+1]+1;
//             }
//         }
        
//         for(int i=0;i<n;++i){
//             res += max(prefix[i], suffix[i]);
//         }

//         return res;
//     }
// };

int main(){
    Solution sol;

    // vector<int> ratings = {1,2,2};
    // vector<int> ratings = {1,3,2,2,1};
    vector<int> ratings = {1,2,87,87,87,2,1};
    cout<<sol.candy(ratings);

    return 0;
}