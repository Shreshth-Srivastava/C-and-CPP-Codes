#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Frequency map appraoch: Time Complexity --> O(T^26) ; Space Complexity -- > O(1)

typedef long long ll;
const ll mod = 1e9 + 7;
ll mod_add(ll a, ll b) {
    a = a % mod; 
    b = b % mod; 
    return ((a + b) % mod);
}

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int nums[26] = {0};
        for (char ch : s) nums[ch - 'a']++;
        while (t--) {
            int cur[26] = {0};
            for (int j = 0; j < 26; j++) {
                if (j == 25 && nums[j] > 0) {
                    cur[0] = mod_add(cur[0], nums[j]);
                    cur[1] = mod_add(cur[1], nums[j]);
                } else {
                    if (j < 25) cur[j + 1] = mod_add(cur[j + 1], nums[j]);
                }
            }
            for (int j = 0; j < 26; j++) nums[j] = cur[j];
        }
        ll cnt = 0;
        for (int i : nums) cnt = mod_add(cnt, i);
        return (int)cnt;
    }
};

// My Solution: Time Complexity --> O(N*T) ; Space Complexity --> O(1)

// class Solution {
// public:
//     int lengthAfterTransformations(string s, int t) {
//         string curr;
//         for(int i=0;i<t;i++){
//             curr = "";
//             for(int j=0;j<s.size();j++){
//                 if(s[j] == 'z'){
//                     curr += "ab";
//                 }
//                 else{
//                     int temp = s[j];
//                     temp++;
//                     curr += char(temp);
//                 }
//             }
//             s = curr;
//         }
//         return curr.size();
//     }
// };

int main(){
    Solution sol;
    string s = "abcyy";
    cout<<sol.lengthAfterTransformations(s, 2);
    return 0;
}