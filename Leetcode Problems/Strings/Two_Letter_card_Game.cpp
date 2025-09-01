#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

// Time Complexity --> O(N) ; Space Complexity --> O(2*26) ==> O(1)

class Solution {
public:
    int score(vector<string>& cards, char x) {
        int xx = 0;
        unordered_map<char, int> cx, xc;

        for(const auto& card: cards){
            if(card[0] == x && card[1] == x){
                xx++;
            }
            else if(card[1] == x){
                cx[card[0]]++;
            }
            else if(card[0] == x){
                xc[card[1]]++;
            }
        }

        auto [pairsCx, leftoverCx] = helper(cx);
        auto [pairsXc, leftoverXc] = helper(xc);

        int totalRemaining = leftoverCx + leftoverXc;
        int additionalPairs = min(xx, totalRemaining);
        xx -= additionalPairs;

        int res = pairsCx + pairsXc;
        res = min(res*2, res + xx/2);

        return res + additionalPairs;
    }
private:
    pair<int, int> helper(unordered_map<char, int>& m){
        if(m.empty())
            return {0,0};

        int total = 0, maxFreq = 0;

        for(const auto& pair: m){
            total += pair.second;
            maxFreq = max(maxFreq, pair.second);
        }

        int pairs = 0, leftovers = 0, sumOther = total - maxFreq;
        if(maxFreq > sumOther){
            pairs = sumOther;
            leftovers = maxFreq - sumOther;
        }
        else{
            pairs = total / 2;
            leftovers = total % 2;
        }

        return {pairs, leftovers};
    }
};

// Time Complexity --> O(N) ; Space Complexity --> O(2*26) ==> O(1)

/*class Solution
{
public:
    int score(vector<string> &cards, char x)
    {

        int ans = 0;
        int f = 0;
        int tf = 0;
        int s = 0;
        int ts = 0;
        int xx = 0;
        int used = 0;
        vector<int> dict1(26, 0);
        vector<int> dict2(26, 0);

        for (int i = 0; i < cards.size(); ++i)
        {

            char c1 = cards[i][0];
            char c2 = cards[i][1];

            if (c1 == x && c2 == x)
                xx++;
            else if (c1 == x)
            {

                dict1[c2 - 'a']++;
                f = max(dict1[c2 - 'a'], f);
                tf++;
            }
            else if (c2 == x)
            {

                dict2[c1 - 'a']++;
                s = max(dict2[c1 - 'a'], s);
                ts++;
            }
        }

        if (f > (tf - f))
        {

            ans += (tf - f);
            tf = f - (tf - f);
        }
        else
        {

            ans += tf / 2;
            tf = tf % 2;
        }

        if (s > (ts - s))
        {

            ans += (ts - s);
            ts = s - (ts - s);
        }
        else
        {

            ans += ts / 2;
            ts = ts % 2;
        }

        used += min(tf + ts, xx);
        xx -= min(tf + ts, xx);
        ans = min(ans * 2, ans + xx / 2);
        ans += used;

        return ans;
    }
};*/

int main()
{
    Solution sol;

    vector<string> cards = {"ab", "aa", "ab", "bc", "cc", "bc", "bb", "ac", "bc", "bc", "aa", "aa", "ba", "bc", "cb", "ba", "ac", "bb", "cb", "ac", "cb", "cb", "ba", "bc", "ca", "ba", "bb", "cc", "cc", "ca", "ab", "bb", "bc", "ba", "ac", "bc", "ac", "ac", "bc", "bb", "bc", "ac", "bc", "aa", "ba", "cc", "ac", "bb", "ba", "bb"};

    cout << sol.score(cards, 'b');

    return 0;
}