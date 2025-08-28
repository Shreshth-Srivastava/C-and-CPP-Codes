#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> m;
public:
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (m.find(key) == m.end()) {
            return "";
        }
        
        int start = 0;
        int end = m[key].size() - 1;
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (m[key][mid].first < timestamp) {
                start = mid + 1;
            } else if (m[key][mid].first > timestamp) {
                end = mid - 1;
            } else {
                return m[key][mid].second;
            }
        }
        
        if (end >= 0) {
            return m[key][end].second;
        }
        return "";
    }
};