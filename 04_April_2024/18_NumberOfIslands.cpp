// https://leetcode.com/problems/number-of-islands/?envType=daily-question&envId=2024-04-19

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    void bfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int row, int col) {
        int m = grid.size(), n = grid[0].size();

        visited[row][col] = true;
        queue<pair<int, int>> q;
        q.push(pair<int, int>({row, col}));

        vector<int> shiftRow = {-1, 0, 1, 0}, shiftCol = {0, 1, 0, -1};

        while(q.size()){
            pair<int, int> p = q.front();
            q.pop();

            int r = p.first, c = p.second;
            for(int i = 0; i < 4; ++i) {
                int newRow = r + shiftRow[i];
                int newCol = c + shiftCol[i];

                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n) {
                    if (grid[newRow][newCol] == '1' && !visited[newRow][newCol]) {
                        visited[newRow][newCol] = true;
                        q.push(pair<int, int>({newRow, newCol}));
                    }
                }
            }
        }

        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        int count = 0;

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    ++count;
                    bfs(grid, visited, i, j);
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