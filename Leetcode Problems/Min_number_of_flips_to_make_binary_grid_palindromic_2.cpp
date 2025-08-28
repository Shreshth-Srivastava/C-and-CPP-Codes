#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Time Complexity -- O(Row*Col) ; Space Complexity --> O(1)

class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        //s_one == same '1' , diff = '1' , '0' these are used when there are odd rows or columns.
        int count=0,s_one=0,diff=0;

        for(int i=0;i<m/2+m%2;i++){
            for(int j=0;j<n/2+n%2;j++){
                //checking no of ones;
                int a=grid[i][j],b=grid[i][n-1-j],c=grid[m-1-i][j],d=grid[m-1-i][n-1-j];
                int one=0;
                
                if(a==1) one++;
                if(b==1) one++;
                if(c==1) one++;
                if(d==1) one++;

                //midpoint is always converted to 0 to balance it so that there will alaways be a remainder of 2 or 4  when solving for palindrome.
                if(j==n-1-j && i==m-1-i and grid[i][j]==1){
                    count++;
                }else 
                //The next two if statements are for odd row or column. 
                if(j==n-1-j){
                    if(b!=c){
                        diff++;
                        count++;
                    }
                    else {
                        if(b==1) s_one++;
                    }
                }else if(i==m-1-i){
                    if(a!=d) {diff++;count++;}
                    else {
                        if(a==1) s_one++;
                    }
                }else{//this part contains the compulsory changes required to be a palindrome.
                    if(one == 2){
                        count+=2;
                    }
                    if(one == 1 || one == 3) {
                        count++;
                    }
                }
            }
        }
        //till here when there are odd row or column the remainder after the above loops would by 0 or 2.
        //after compulsory changes the matrix will always be divisible by 4 except when it has odd row or column.
        //the below are for the changes which happen during the odd row or column.
        if((2*s_one+2*diff)%4==0 || (2*s_one)%4==0) return count;
        if(diff>=2) return count;
        //if difference is less than that meaning even when converting 0,1 into 1,1 we cannot make it so that the number of one's is divisible by 4.
        //so here we convert one of the same 1's 1,1 to 0,0 so count+2
        return count+2;
    }
};

// Time Complexity -- O(Row*Col) ; Space Complexity --> O(1)

// Solution-2
/*
class Solution {
public:
    int minFlipsPalindrome(int row,int col,int n,int m,vector<vector<int>>& grid)
    {
       int ans=0;
       int difPair=0;
       int extraOne=0;

       for(int i=0;i<=row;i++)
       {
           for(int j=0;j<=col;j++)
           {
               int totalCostForOne=0;
               int totalCostForZero=0;

               map<pair<int,int>,int>points;
                
               // checking for i,j coordinate
               if(grid[i][j]!=1)
               {
                  totalCostForOne++;
               }
               else
               {
                   totalCostForZero++;
               }
               points[{i,j}]++;
               int newI=n-i-1;
 
               // checking for the bottom coordinate
               if(points.find({newI,j})==points.end())
               {
                    if(grid[newI][j]!=1)
                    {
                        totalCostForOne++;
                    }
                    else
                    {
                        totalCostForZero++;
                    }
                    points[{newI,j}]++;
               }

               int newJ=m-j-1;
  
               // checking for right coordinate
               if(points.find({i,newJ})==points.end())
               {
                    if(grid[i][newJ]!=1)
                    {
                        totalCostForOne++;
                    }
                    else
                    {
                        totalCostForZero++;
                    }
                    points[{i,newJ}]++;
               }
 
               // checking for bottom right coordinate
               if(points.find({newI,newJ})==points.end())
               {
                    if(grid[newI][newJ]!=1)
                    {
                        totalCostForOne++;
                    }
                    else 
                    {
                        totalCostForZero++;
                    }
                    points[{newI,newJ}]++;
               }
               
               if(points.size()==4)
               {
                  ans+=min(totalCostForZero,totalCostForOne);
               }

                if(points.size()==1)
                {
                     if(grid[i][j]==1)
                       ans++;
                }

                if(points.size()==2)
                {
                    difPair+=min(totalCostForZero,totalCostForOne);
                    if(totalCostForOne==0)
                    {
                        extraOne+=2;
                    }
                }

           }
       }
     
       extraOne%=4;

       if(difPair>0)
       {
          extraOne=0;
       }
       
       ans+=difPair;

       ans+=extraOne;

       return ans;
    }

    int minFlips(vector<vector<int>>& grid) 
    {   
        int n=grid.size();
        int m=grid[0].size();
        int row=(n-1)/2;
        int col=(m-1)/2;
        int ans=minFlipsPalindrome(row,col,n,m,grid);
        return ans;
    }
};
*/

int main(){
    Solution sol;
    
    // vector<vector<int>> grid = {{1,0,0},{0,1,0},{0,0,1}};
    vector<vector<int>> grid = {{0,0,1},{1,1,1}};

    cout<<sol.minFlips(grid);

    return 0;
}