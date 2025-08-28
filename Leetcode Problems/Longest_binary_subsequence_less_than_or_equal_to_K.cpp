#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;

// Editorial (Greedy Approach): Time Complexity --> O(N) ; Space Complexity --> O(1)

/*class Solution {
public:
    int longestSubsequence(string s, int k) {
        int sm = 0;
        int cnt = 0;
        int bits = 32 - __builtin_clz(k);
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[s.size() - 1 - i];
            if (ch == '1') {
                if (i < bits && sm + (1 << i) <= k) {
                    sm += 1 << i;
                    cnt++;
                }
            } else {
                cnt++;
            }
        }
        return cnt;
    }
};*/

// Greedy Approach - 2

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n=s.size();
        reverse(s.begin(),s.end());
        int cnt=0;//count will maintain our answer and will also help in calculating what next value we will add in our val when next '1' comes because we also want index.
        long long val=0;
        for(int i=0;i<n;i++){
            long long num=s[i]-'0';
            if((num*pow(2,cnt)+val)<=k){
                val=val+num*pow(2,cnt);
                cnt++;
            }
        }
        return cnt;
    }
};

// DP Solution: Time Complexity --> O(N^3) because of pow() else O(N^2) ; Space Complexity --> O(N^2)

/*class Solution {
public:
    int f(int i, int size, int sum, string &s, vector<vector<int>>& dp) {
        if (i < 0) return 0;
        if (dp[i][size] != -1) return dp[i][size];

        int no = f(i - 1, size, sum, s, dp);
        int yes = 0;

        if ((sum - (s[i] - '0') * pow(2, size)) >= 0) {
            yes = 1 + f(i - 1, size + 1, sum - (s[i] - '0') * pow(2, size), s, dp);
        }

        return dp[i][size] = max(no, yes);
    }

    int longestSubsequence(string s, int k) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(n - 1, 0, k, s, dp);
    }
};*/

// My Solution (DP) : MLE

/*class Solution {
public:
    int longestSubsequence(string s, int k) {
        // return dfs(s, 0, 0, k);
        return dfs(s, 0, convert(s), k, 0);
    }
private:
    int convert(string s){
        int n = s.size(), res = 0;
        for(int i=n-1;i>=0;--i){
            int temp = s[i] - '0';
            res += pow(2, (n-1 - i)) * temp;
        }
        return res;
    }

    int dfs(string& s, int idx, int curr, int k){
        if(idx == s.size()){
            int val = convert(s);
            return val <= k ? s.size() : 0;
        }
        
        // Take
        int take = dfs(s, idx+1, curr, k);

        // Not Take
        string temp = s;
        temp = temp.erase(idx,1);
        int notTake = dfs(temp, idx, curr, k);

        return max(take, notTake);
    };

    // Approach - 2
    int dfs(string& s, int idx, int curr, int k, int res){
        if(idx == s.size()){
            return curr <= k ? res : 0;
        }

        // Take
        int take = dfs(s, idx+1, curr, k, res+1);

        // Not Take
        int i = s.size() - 1 - idx;
        curr -= pow(2,i) * (s[idx] - '0');
        int notTake = dfs(s, idx+1, curr, k, res);

        return max(take, notTake);
    };

};*/

int main(){
    Solution sol;

    // string s = "0";
    // int k = 1;

    // string s = "11";
    // int k = 2;

    // string s = "101";
    // int k = 3;

    // string s = "11";
    // int k = 3;

    string s = "1001010";
    int k = 5;

    // string s = "00101001";
    // int k = 1;

    cout<<sol.longestSubsequence(s, k);

    return 0;
}