#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Time Complexity --> O(NlogN) ; Space Complexity --> O(1) 

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int res = 0, ptr1 = 0, ptr2 = 0;

        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        
        while(ptr1 < g.size() && ptr2 < s.size()){
            if(g[ptr1] <= s[ptr2]){
                ptr1++;
                res++;
            }
            ptr2++;
        }

        return res;
    }
};

int main(){
    Solution sol;

    vector<int> g = {10,9,8,7};
    vector<int> s = {5,6,8,8};

    cout<<sol.findContentChildren(g, s);

    return 0;
}