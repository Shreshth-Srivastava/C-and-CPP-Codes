#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> counts;
        for (int x : basket1) {
            counts[x]++;
        }
        for (int x : basket2) {
            counts[x]++;
        }

        long long cheapest_fruit_globally = 1e9 + 7;
        for (auto const& [cost, count] : counts) {
            if (count % 2 != 0) {
                return -1;
            }
            cheapest_fruit_globally = min(cheapest_fruit_globally, (long long)cost);
        }

        vector<int> misplaced1, misplaced2;
        unordered_map<int, int> b1_counts;
        for (int x : basket1) {
            b1_counts[x]++;
        }

        for (auto const& [cost, count] : counts) {
            int b1_count = b1_counts[cost];
            int needed_count = count / 2;
            if (b1_count > needed_count) {
                for (int i = 0; i < b1_count - needed_count; ++i) {
                    misplaced1.push_back(cost);
                }
            } else if (b1_count < needed_count) {
                for (int i = 0; i < needed_count - b1_count; ++i) {
                    misplaced2.push_back(cost);
                }
            }
        }

        sort(misplaced1.begin(), misplaced1.end());
        sort(misplaced2.rbegin(), misplaced2.rend());

        long long total_cost = 0;
        int n_swaps = misplaced1.size();
        for (int i = 0; i < n_swaps; ++i) {
            long long direct_swap_cost = min(misplaced1[i], misplaced2[i]);
            long long temp_swap_cost = 2 * cheapest_fruit_globally;
            total_cost += min(direct_swap_cost, temp_swap_cost);
        }

        return total_cost;
    }
};

int main(){
    Solution sol;

    vector<int> basket1 = {4,2,2,2};
    vector<int> basket2 = {1,4,1,2};

    cout<<sol.minCost(basket1, basket2);

    return 0;
}