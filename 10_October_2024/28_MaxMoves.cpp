// https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/?envType=daily-question&envId=2024-10-29

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    int maxans = 0;
    vector<vector<int>>dp;
    
    int solve(int i, int j, int n, int m, vector<vector<int>>& grid, int prev) {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] <= prev) {
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int top = solve(i - 1, j + 1, n, m, grid, grid[i][j]);
        int mid = solve(i, j + 1, n, m, grid, grid[i][j]);
        int bot = solve(i + 1, j + 1, n, m, grid, grid[i][j]);

        return dp[i][j]=1 + max({top, mid, bot});
    }
    
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        dp=vector<vector<int>>(n,vector<int>(m,-1));
        for (int i = 0; i < n; i++) {
            maxans = max(maxans, solve(i, 0, n, m, grid, -1));
        }
        
        return maxans-1;
    }
};

int main () {
    
    return 0;
}
