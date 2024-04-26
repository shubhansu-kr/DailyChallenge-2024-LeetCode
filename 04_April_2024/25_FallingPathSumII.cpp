// https://leetcode.com/problems/minimum-falling-path-sum-ii/?envType=daily-question&envId=2024-04-26

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int solve(vector<vector<int>> &grid, int i, int j) {
        if (j >= grid.size()) return 0;

        
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();

        int ans = 0;
        int sum = INT_MAX;
        for(int j = 0; j < n; ++j) {
            sum = min(sum, grid[0][j] + solve(grid, 0, j));
        }
        ans += sum;

        return ans;
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