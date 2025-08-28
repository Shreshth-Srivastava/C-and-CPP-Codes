#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Editiorial Solution

class Solution {
public:
    int maxDifference(string s, int k) {
        auto getStatus = [](int cnt_a, int cnt_b) -> int {
            return ((cnt_a & 1) << 1) | (cnt_b & 1);
        };

        int n = s.size();
        int ans = INT_MIN;
        for (char a = '0'; a <= '4'; ++a) {
            for (char b = '0'; b <= '4'; ++b) {
                if (a == b) {
                    continue;
                }
                int best[4] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX};
                int cnt_a = 0, cnt_b = 0;
                int prev_a = 0, prev_b = 0;
                int left = -1;
                for (int right = 0; right < n; ++right) {
                    cnt_a += (s[right] == a);
                    cnt_b += (s[right] == b);
                    while (right - left >= k && cnt_b - prev_b >= 2) {
                        int left_status = getStatus(prev_a, prev_b);
                        best[left_status] =
                            min(best[left_status], prev_a - prev_b);
                        ++left;
                        prev_a += (s[left] == a);
                        prev_b += (s[left] == b);
                    }
                    int right_status = getStatus(cnt_a, cnt_b);
                    if (best[right_status ^ 0b10] != INT_MAX) {
                        ans =
                            max(ans, cnt_a - cnt_b - best[right_status ^ 0b10]);
                    }
                }
            }
        }
        return ans;
    }
};

/*class Solution {
public:
    int maxDifference(string& s, int k) {
        int res = INT_MIN, l = 0, h = 0, n = s.size(), even = INT_MAX, odd = INT_MIN, step = 1;
        vector<int> arr(5, 0);
                
        while(l != n-k){
            while(h-l+1 <= k){
                arr[s[h] - '0']++;
                step = 1;
                h += step;
            }

            check(arr, odd, even, res);

            if(h<n && h-l+1 > k){
                if(step == -1){
                    arr[s[h] - '0']--;
                }
                else{
                    arr[s[h] - '0']++;
                }
                h += step;
            }
            else{
                if(step == -1 && h-l+1 < k){
                    arr[s[l] - '0']--;
                    l++;
                    step = 1;
                    check(arr, odd, even, res);
                    h += step;
                    arr[s[h] - '0']++;
                }

                else{
                    if(h == n){
                        arr[s[l] - '0']--;
                        l++;
                        step = -1;
                        h += step;
                    }
                }
            }
        }

        return res;
    }
private:
    void check(vector<int>& arr, int& odd, int& even, int& res){
        odd = INT_MIN, even = INT_MAX;
        for(const auto& elem: arr){
            if(elem == 0) continue;
            if(elem&1){
                odd = max(odd, elem);
            }
            else{
                even = min(even, elem);
            }
        }

        if(odd != INT_MIN && even != INT_MAX){
            res = max(res, odd-even);
        }
    }
};*/

int main(){
    Solution sol;

    string s = "1122211";
    int k = 3;

    // string s = "110";
    // int k = 3;

    cout<<sol.maxDifference(s, k);

    return 0;
}