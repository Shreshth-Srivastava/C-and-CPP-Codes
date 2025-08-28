#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

// Time Complexity --> O(N) ; Space Complexity --> O(N)

typedef long long ll;

class Solution {
private:
    long long countLCT(const string& s) {
    ll count_L = 0;
    ll count_LC = 0;
    ll count_LCT = 0;

    for (const auto& ch : s) {
        if (ch == 'L') {
            count_L++;
        } else if (ch == 'C') {
            count_LC += count_L;
        } else if (ch == 'T') {
            count_LCT += count_LC;
        }
    }

    return count_LCT;
}

public:
    long long numOfSubsequences(string s) 
    {
        const int n = s.size();
        ll ans = countLCT(s);

        string s1 = 'L' + s, s2 = s + 'T';

        ll ans1 = countLCT(s1), ans2 = countLCT(s2);

        ans1 -= ans;
        ans2 -= ans;

        ll ans3 = 0;
        vector<int> suff(n,0);

        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='T') 
                suff[i]=1;

            if(i+1<n) 
                suff[i] += suff[i+1];
        }

        ll st = s[0] == 'L' ? 1 : 0;

        for(int i=1;i<n;i++)
        {
            ans3 = max(ans3, (st)*suff[i]);
            if(s[i]=='L') st++;
        }
        
        return ans+max(ans1,max(ans2,ans3));
    }
};

int main(){
    Solution sol;

    cout<<sol.numOfSubsequences("LCLPTTGC");

    return 0;
}