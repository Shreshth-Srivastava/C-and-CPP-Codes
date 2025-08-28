#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Stack Solution

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<pair<int, int>> stk;
        vector<int> answer(n, 0);
        for (int i = 0; i < n; i++) {
            int currDay = i;
            int currTemp = temperatures[i];
            
            while (!stk.empty() && stk.top().second < currTemp) {
                int prevDay = stk.top().first;
                int prevTemp = stk.top().second;
                stk.pop();
                
                answer[prevDay] = currDay - prevDay;
            }
            
            stk.push({currDay, currTemp});
        }
        return answer;
    }
};

// Two Pointer Solution [My Solution]

/*class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int ptr1, ptr2, n = temperatures.size(), count;
        vector<int> answer(n, 0);
        if(n == 1) return answer;
        for(int i=0;i<n;i++){
            count = 0;
            ptr1 = i;
            for(int j=i+1;j<n;j++){
                ptr2 = j;
                if(temperatures[ptr2] > temperatures[ptr1]){
                    answer[i] = count;
                }
                else count++;
            }
        }
        return answer;
    }
};*/

int main(){
    Solution sol;
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    sol.dailyTemperatures(temperatures);
    return 0;
}