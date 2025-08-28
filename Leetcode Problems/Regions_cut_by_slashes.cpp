#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> par;
	int findPar(int u){
        if(par[u]==u){
            return u;
        }
        return findPar(par[u]);
    }
    
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int N = n+1;
        
        /*Approach: For a grid of nxn, make a N+1xN+1 Matrix, which is divided into 
        pixels like, for a 2x2, make this --->
        
        (0,0)-----(0,1)-----(0,2)
        |          |          |
        |          |          |
        (1,0)-----(1,1)-----(1,2)
        |          |          |
        |          |          |
        (2,0)-----(2,1)----(2,2)
        
        For the starting, Consider that the borders ={0,0},{0,1},{0,2},{1,0},{1,1},{1,2}
        {2,0},{2,1},{2,2} have a Parent at (0,0) to represent a figured of graph
        
        
        Now, there will be two cases:
        
        Case 1 --->
        At grid[row][col], I have '/' ---->
        
        here,   (r,c)---(r,c+1)
                    |  /
                    | /
                    |/       
                 (r+1, c)  so, for (r,c) => Union find (r+1,c) & (r, c+1)
        
        Case 2 ---->
        At grid[row][col], I have '\\'  --->
        
        here,   (r,c)
                    \
                     \
                      \
                       (r+1, c+1) ====> So, Union find (r, c) & (r+1, c+1)
                       
        Last Step : Calculation of answers,
        
        for this, whenever we detect a cycle during Union Find, increment the answer as 
        the borders are already connected to a single parent meaning there will be a divide*/
        
        
        
        par.resize(N*N);
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(i==0 || j==0 || i==N-1 || j==N-1){
                    par[i*N+j]=0; //All Borders & edges are parent at 0
                }
                else par[i*N+j]=i*N+j;
            }
        }
        int cycle = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='/'){
                    int cord1 = i*N + (j+1);
                    int cord2 = (i+1)*N + j;
                    int p1 = findPar(cord1);
                    int p2 = findPar(cord2);
                     
                    if(p1==p2){
                         
                        cycle++;
                    }
                    else if(p1!=p2){
                        par[p1]=p2;
                    }
                }
                else if(grid[i][j]=='\\'){
                    int cord1 = i*N + (j);
                    int cord2 = (i+1)*N + (j+1);
                    int p1 = findPar(cord1);
                    int p2 = findPar(cord2);
                    
                    if(p1==p2){
                        cycle++;
                    }
                    else if(p1!=p2){
                        par[p1]=p2;
                    }
                }
            }
        }
        return cycle;
        
    }
};

int main(){
    Solution sol;
    vector<string> grid = {" /","/ "};
    cout<<sol.regionsBySlashes(grid);
    return 0;
}