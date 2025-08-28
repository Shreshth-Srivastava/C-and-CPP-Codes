#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// My Solution (Using HINT): Time Complexity --> O(N) ; Space Complexity --> O(N) 
class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        if(n == 2) return 0;

        n++;

        vector<int> left(n, INT_MAX);
        vector<int> right(n, INT_MIN);
        vector<int> top(n, INT_MAX);
        vector<int> bottom(n, INT_MIN);

        for(const auto& elem: buildings){
            int x = elem[0], y = elem[1];

            left[y] = min(left[y], x);
            right[y] = max(right[y], x);
            top[x] = min(top[x], y);
            bottom[x] = max(bottom[x], y);
        }
        

        int res = 0;
        for(const auto& elem: buildings){
            int x = elem[0], y = elem[1];

            if(left[y] < x && x < right[y] && top[x] < y && y < bottom[x]){
                res++;
            }
        }
        
        return res;
    }
};

// My Solution --> TLE

/*class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        if(n == 2) return 0;

        vector<vector<bool>> arr(n, vector<bool>(n, false));

        for(const auto& elem: buildings){
            int row = elem[1], col = elem[0];
            arr[row-1][col-1] = true;
        }

        int res = 0;

        for(int i=1;i<n-1;++i){
            for(int j=1;j<n-1;++j){
                if(arr[i][j]){
                    if(check(i,j,arr, n)){
                        res++;
                    }
                }
            }
        }

        return res;
    }
private:
    bool check(int row, int col, vector<vector<bool>>& arr, int n){
        bool top = false, right = false, bottom = false, left = false;

        for(int i=row-1;i>=0;--i){
            if(arr[i][col]){
                top = true;
            }
        }

        for(int j=col+1;j<n;++j){
            if(arr[row][j]){
                right = true;
            }
        }

        for(int i=row+1;i<n;++i){
            if(arr[i][col]){
                bottom = true;
            }
        }

        for(int j=col-1;j>=0;--j){
            if(arr[row][j]){
                left = true;
            }
        }

        return top && right && bottom && left;
    }
};*/

int main(){
    Solution sol;

    // vector<vector<int>> buildings = {{1,2},{2,2},{3,2},{2,1},{2,3}};
    // cout<<sol.countCoveredBuildings(3, buildings);

    vector<vector<int>> buildings = {{1,2},{2,1},{3,1},{1,1},{2,3},{3,2},{1,3}};
    cout<<sol.countCoveredBuildings(3, buildings);

    return 0;
}