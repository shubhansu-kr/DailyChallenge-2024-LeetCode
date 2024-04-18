// https://leetcode.com/problems/island-perimeter/?envType=daily-question&envId=2024-04-18

#include <bits/stdc++.h>
using namespace std ;

class Solution1 {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        int perimeter = 0;
        vector<int> shiftRow = {-1, 0, 1, 0}, shiftCol = {0, 1, 0, -1};

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    for(int k = 0; k < 4; ++k) {
                        int newRow = i + shiftRow[k];
                        int newCol = j + shiftCol[k];
                        if (newCol >= 0 && newRow >= 0 && newRow < m && newCol < n) {
                            if (!grid[newRow][newCol]) {
                                ++perimeter;
                            }
                        }
                        else {
                            ++perimeter;
                        }
                    }
                }
            }
        }
        return perimeter;        
    }
};

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));

        queue<pair<int, int>> q;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j) {
                if (grid[i][j]){
                    q.push(pair<int, int>({i, j}));
                    visited[i][j] = true;
                    break;
                }
            }
        }

        int perimeter = 0;

        vector<int> shiftRow = {-1, 0, 1, 0}, shiftCol = {0, 1, 0, -1};

        while(q.size()) {
            pair<int, int> p = q.front();
            q.pop();

            int row = p.first, col = p.second();

            for(int i = 0; i < 4; ++i) {
                int newRow = row + shiftRow[i];
                int newCol = col + shiftCol[i];

                // check valid
                if (newCol >= 0 && newRow >= 0 && newRow < m && newCol < n) {

                    if (grid[newRow][newCol]) {
                        if (!visited[newRow][newCol]){
                            q.push(pair<int, int>({newRow, newCol}));
                            visited[newRow][newCol] = true;
                        }
                    }
                    else {
                        ++perimeter;
                    }
                }
                else {
                    ++perimeter;
                }
            }
        }
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