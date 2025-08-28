#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

// Time Complexity --> O(N*26) ; Space Complexity --> O(26)

class Solution {
public:
    int maxSubstrings(string word) {
        int len = 0;

        vector<int> arr(26, -1);
        int n = word.length();
        
        for(int i = 0; i < n; i++) {
            int idx = word[i] - 'a';
            if(arr[idx] != -1 && i - arr[idx] + 1 >= 4) {
                len++;
                for(int i = 0; i < 26; i++) {
                    arr[i] = -1;
                }
            } else {
                if(arr[idx] == -1) {
                    arr[idx] = i;
                }
            }
        }

        return len;
    }
};

int main(){
    Solution sol;
    // string word = "abcdeafdef";
    // string word = "bcdaaaab";
    // string word = "aaaeaaa";
    // string word = "aabececbbeccdcdcbbdece";
    string word = "abaeabbcdadcecdcccbbcb";
    cout<<sol.maxSubstrings(word);
    return 0;
}