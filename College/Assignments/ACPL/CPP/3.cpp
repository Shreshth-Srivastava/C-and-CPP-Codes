#include<iostream>
using namespace std;

class Solution{
public:
    int fibonacci(int n){
        if(n < 0){
            cout<<"Invalid value of n";
            return -1;
        }
        if(n == 0 || n == 1) return 1;
        return fibonacci(n-1) + fibonacci(n-2);
    }
};

int main(){
    Solution sol;
    cout<<sol.fibonacci(5);
    return 0;
}