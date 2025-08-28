#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Time Complexity --> O(N + 26^2) ; Space Complexity --> O(1)

class Solution {
public:
    int minimumDeletions(string word, int k) {
        int freq[26] = {0};

        for(const auto& c:word){
            freq[c - 'a']++;
        }

        int res = word.size();

        for(int i=0;i<26;++i){
            if(freq[i] == 0)
                continue;

            int curr = 0;
            for(int j=0;j<26;++j){
                if(freq[j] < freq[i])
                    curr += freq[j];
                if(freq[j] > freq[i]+k)
                    curr += (freq[j] - (freq[i]+k));
            }
            res = min(curr, res);
        }

        return res;
    }
};

int main(){
    Solution sol;

    cout<<sol.minimumDeletions("dabdcbdcdcd", 2);
    // cout<<sol.minimumDeletions("ddwddddwdddw", 1);

    return 0;
}