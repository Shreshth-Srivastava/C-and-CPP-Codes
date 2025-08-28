#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Using Formula

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26,0);
        int max_freq=0, count_maxfreq=0, sz=tasks.size();
        for(char i:tasks){
            mp[i-'A']++;
            max_freq = max(max_freq, mp[i-'A']);
        }   
        for(int i=0;i<26;i++) if(mp[i] == max_freq) count_maxfreq++;
        int time = (max_freq-1)*(n+1)+count_maxfreq;
        return max(time,sz);
    }
};

// Another solution

/*class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0) {
            return tasks.size();
        }

        vector<int> count(26, 0);
        for (int i = 0; i < tasks.size(); ++i) {
            count[tasks[i] - 'A']++;
        }
        sort(count.begin(), count.end(), greater<int>());
        int initial = (count[0] - 1) * (n + 1) + 1;
        int spots = initial - count[0];
        int ans = initial;
        for (int i = 1; i < count.size() && count[i] > 0; ++i) {
            if (count[i] == count[0]) {
                ++ans;
                spots -= (count[i] - 1);
            } else {
                spots -= count[i];
            }
        }
        if (spots >= 0)
            return ans;
        else 
            return ans - spots;
    }
};*/

// Neetcode Solution

/*class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        queue<vector<int>> q;
        vector<int> counter(26);

        for (int i = 0; i < tasks.size(); ++i)
            ++counter[tasks[i] - 'A'];
        for (int i = 0; i < 26; ++i){
            if (counter[i])
                pq.push(counter[i]);
        }

        int time = 0;
        while (!q.empty() || !pq.empty()){
            ++time;
            if (!pq.empty()){
                if (pq.top() - 1)
                    q.push({pq.top() - 1, time + n});
                pq.pop();
            }
            if (!q.empty() && q.front()[1] == time){
                pq.push(q.front()[0]);
                q.pop();
            }
        }
        return time;
    }
};*/

// My Solution, need improvements

/*class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for(int i=0;i<tasks.size();i++) count[tasks[i] - 'A']++;
        sort(count.begin(), count.end(), greater<int>());
        for(int j=0;count[j] != 0;j++){
            int temp = count[j];
            int val = j;
            while(temp > 0){
                while(s.count(val)) val++;
                q.push(val);
                s.insert(val);
                val += (n+1);
                temp--;
            }
        }
        // int res = 0;
        // while(!q.empty()){
        //     if(q.top() == res){
        //         q.pop();
        //     }
        //     res++;
        // }
        return (q.top()+1);
    }
private:
    priority_queue<int, vector<int>> q;
    unordered_set<int> s;
};*/

int main(){
    Solution sol;
    vector<char> tasks = {'A','A','A','B','B','B', 'C','C','C', 'D', 'D', 'E'};
    cout<<sol.leastInterval(tasks, 2);
    return 0;
}