#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Much Simpler Editorial Solution
/*class Solution {
public:
    int maxDistance(string s, int k) {
        int latitude = 0, longitude = 0, ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            switch (s[i]) {
                case 'N':
                    latitude++;
                    break;
                case 'S':
                    latitude--;
                    break;
                case 'E':
                    longitude++;
                    break;
                case 'W':
                    longitude--;
                    break;
            }
            ans = max(ans, min(abs(latitude) + abs(longitude) + k * 2, i + 1));
        }
        return ans;
    }
};
*/

// Editorial Solution: Time Complexity --> O(N) ; Space Complexity --> O(1)

class Solution {
public:
    int maxDistance(string& s, int& k) {
        int N = 0, S = 0, W = 0, E = 0, res = INT_MIN;

        for(const auto& c: s){
            if(c == 'N')
                N++;
            if(c == 'S')
                S++;
            if(c == 'W')
                W++;
            if( c == 'E')
                E++;

            int first = min(min(N, S), k);
            int second = min(min(E, W), k - first);
            res = max(res, count(N, S, first) + count(E, W, second));
        }

        return res;
    }

    int count(int drt1, int drt2, int times) {
        return abs(drt1 - drt2) + times * 2;
    }  
};