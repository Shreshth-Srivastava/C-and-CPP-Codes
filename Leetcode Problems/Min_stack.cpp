#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Slightly better solution

class MinStack {
public:
    vector<int> s, minstk;
	int tp = -1;
    MinStack() { }
    
    void push(int val) {
        if(s.empty()){
            s.push_back(val);
            minstk.push_back(val);
            tp++;
        }
        else{
            s.push_back(val);
            minstk.push_back(min(minstk.back(), val));
            tp++;
        }
    }
    
    void pop() { 
        s.pop_back();
        minstk.pop_back();
        tp--;
    }
    
    int top() { 
        return s.back(); 
    }
    
    int getMin() { 
        return  minstk[tp];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

/*class MinStack {
public:
    vector< pair<int,int> > s;
	
    MinStack() { }
    
    void push(int val) {
        if(s.empty())
            s.push_back({val,val});
        else
            s.push_back({val,min(s.back().second,val)});    
    }
    
    void pop() { s.pop_back(); }
    
    int top() { return s.back().first; }
    
    int getMin() { return s.back().second; }
};*/

int main(){
    MinStack stk;
    stk.push(1);
    stk.push(2);
    cout<<"top: "<<stk.top()<<endl;
    cout<<"min: "<<stk.getMin()<<endl;
    stk.pop();
    cout<<"min: "<<stk.getMin()<<endl;
    cout<<"top: "<<stk.top()<<endl;
    return 0;
}