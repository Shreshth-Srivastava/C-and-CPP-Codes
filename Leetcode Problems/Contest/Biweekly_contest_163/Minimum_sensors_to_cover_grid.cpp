#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Property of ceil :-

ceil of (a/b) = (a + b - 1) / b;

*/

class Solution {
public:
    int minSensors(int n, int m, int k) {
        int coverageSide = 2*k+1, sensorsRows = (n + coverageSide - 1) / coverageSide;
        int sensorsCols = (m + coverageSide - 1) / coverageSide;

        return sensorsRows*sensorsCols;
    }
};