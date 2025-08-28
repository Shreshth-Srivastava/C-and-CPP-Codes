#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ptr1 = 0, ptr2 = n-1;
        int area = min(height[0],height[n-1]) * (n-1);
        int temp;
        while(ptr1<ptr2){
            temp = min(height[ptr1],height[ptr2]) * (ptr2-ptr1);
            area = max(temp, area);
            
            if(height[ptr1] <= height[ptr2]) ptr1++;
            else ptr2--;
            
        }
        return area;
    }
};

int main(){
    Solution sol;
    vector<int> height = {1,2,4,3};
    cout<<sol.maxArea(height)<<endl;
    return 0;
}