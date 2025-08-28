#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(a<b) swap(a,b);
    while(b != 0){
        int temp = a%b;
        a = b;
        b = temp;
    }
    return a;
}