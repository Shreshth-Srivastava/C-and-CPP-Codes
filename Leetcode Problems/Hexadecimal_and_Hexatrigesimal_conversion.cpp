#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

class Solution {
public:
    string concatHex36(int n) {
        // return toHexadecimal(n*n).append(toHexatrigesimal(n*n*n));
        return toHexatrigesimal(n*n*n);
    }
private:
    string toHexadecimal(int n){
        string res = "";
        while(n > 16){
            int temp = n/16;
            cout<<"temp: "<<temp<<endl;

            if(temp > 16){
                res.append(toHexadecimal(temp));
            }
            else{
                if(temp < 10){
                    res.append(1, '0'+temp);
                }
                else{
                    res.append(1, 'A'+(temp-10));
                }
            }
            
            cout<<"n: "<<n<<endl;
            n %= 16;
            cout<<"n%16: "<<n<<endl;
        }
        if(n > 16){
            res.append(toHexadecimal(n));
        }
        else{
            if(n < 10){
                res.append(1, '0'+n);
            }
            else{
                res.append(1, 'A'+(n-10));
            }
        }
        cout<<res;
        return res;        
    }

    string toHexatrigesimal(int n){
        string res = "";

        if(n < 36){
            if(n < 10){
                res.append(1, '0'+n);
            }
            else{
                res.append(1, 'A'+(n-10));
            }
            return res;
        }

        while(n >= 36){
            int temp = n/36;
            cout<<"temp: "<<temp<<endl;

            if(temp >= 36){
                res.append(toHexatrigesimal(temp));
                cout<<"Res: "<<res<<endl;
            }
            else{
                if(temp < 10){
                    res.append(1, '0'+temp);
                    cout<<"Res: "<<res<<endl;
                }
                else{
                    res.append(1, 'A'+(temp-10));
                    cout<<"Res: "<<res<<endl;
                }
            }
            
            cout<<"n: "<<n<<endl;
            n %= 36;
            cout<<"n%36: "<<n<<endl;
        }
        if(n > 36){
            res.append(toHexatrigesimal(n));
        }
        else{
            if(n < 10){
                res.append(1, '0'+n);
            }
            else{
                res.append(1, 'A'+(n-10));
            }
        }
        cout<<res;
        return res;  
    }
};

int main(){
    Solution sol;

    sol.concatHex36(36);

    return 0;
}