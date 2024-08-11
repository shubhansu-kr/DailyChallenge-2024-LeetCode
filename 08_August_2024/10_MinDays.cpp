// https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/?envType=daily-question&envId=2024-08-11

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int minDays(vector<vector<int>>& grid) {

        cin.tie(nullptr)->sync_with_stdio(0);
        nRow = grid.size();
        nCol = grid[0].size();

        if (NumConnectedComponent(grid) != 1)
            return 0;

        for (int i = 0; i < nRow; ++i) {
            for (int j = 0; j < nCol; ++j) {

                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    if (NumConnectedComponent(grid) != 1)
                        return 1;
                    grid[i][j] = 1;
                }
            }
        }

        return 2;
    }

private:
    int nRow;
    int nCol;
    void dfs(int i, int j, vector<vector<int>>& grid,
             vector<vector<bool>>& visted) {
        if (i < 0 || i >= nRow || j < 0 || j >= nCol || grid[i][j] == 0 ||
            visted[i][j])
            return;

        visted[i][j] = 1;

        dfs(i, j - 1, grid, visted);
        dfs(i - 1, j, grid, visted);
        dfs(i, j + 1, grid, visted);
        dfs(i + 1, j, grid, visted);
    }
    int NumConnectedComponent(vector<vector<int>>& grid) {

        int countConComp = 0;
        vector<vector<bool>> visted(nRow, vector<bool>(nCol, 0));
        for (int i = 0; i < nRow; ++i) {
            for (int j = 0; j < nCol; ++j) {

                if (grid[i][j] == 1 && !visted[i][j]) {
                    dfs(i, j, grid, visted);
                    countConComp += 1;
                }
            }
        }
        return countConComp;
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