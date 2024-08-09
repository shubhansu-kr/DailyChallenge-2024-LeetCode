// https://leetcode.com/problems/magic-squares-in-grid/?envType=daily-question&envId=2024-08-09

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:

    bool check(vector<int> &v){
        int n=v.size();
        sort(v.begin(),v.end());
        for(int i=0; i<n-1; i++){
            if(v[i]==v[i+1]) return false;
            if(v[i]>=10 || v[i]<=0) return false;
        }
        if(v[n-1]>=10 || v[n-1]<=0) return false;
        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid.size();
        int count=0;
        for(int i=0; i<n-2; i++){
            for(int j=0; j<m-2; j++){
                vector<int> v(9);
                v[0]=grid[i][j];
                v[1]=grid[i][j+1];
                v[2]=grid[i][j+2];
                v[3]=grid[i+1][j];
                v[4]=grid[i+1][j+1];
                v[5]=grid[i+1][j+2];
                v[6]=grid[i+2][j];
                v[7]=grid[i+2][j+1];
                v[8]=grid[i+2][j+2];
                if(check(v)){
                    int a=grid[i][j]+grid[i][j+1]+grid[i][j+2];
                int b=grid[i+1][j]+grid[i+1][j+1]+grid[i+1][j+2];
                int c=grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2];

                int d=grid[i][j]+grid[i+1][j]+grid[i+2][j];
                int e=grid[i][j+1]+grid[i+1][j+1]+grid[i+2][j+1];
                int f=grid[i][j+2]+grid[i+1][j+2]+grid[i+2][j+2];

                int g=grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2];
                int h=grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j];

                if(a==b && b==c && c==d && d==e && e==f && f==g && g==h) count++;
                }
            }
        }
        return count;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

int main () {
    
    return 0;
}