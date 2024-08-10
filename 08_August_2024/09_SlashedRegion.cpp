// https://leetcode.com/problems/regions-cut-by-slashes/?envType=daily-question&envId=2024-08-10

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    void numberofislandsDFS(vector<vector<int>>&matrix,int i,int j){
        if(i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() || matrix[i][j] != 0)
            return;
        matrix[i][j] = 1;  
        numberofislandsDFS(matrix, i+1, j);
        numberofislandsDFS(matrix, i-1, j);
        numberofislandsDFS(matrix, i, j+1);
        numberofislandsDFS(matrix, i, j-1);
    }

    int regionsBySlashes(vector<string>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int regions = 0;
        vector<vector<int>> matrix(rows * 3, vector<int>(cols * 3, 0));

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == '/') {
                    matrix[i * 3][j * 3 + 2] = 1;
                    matrix[i * 3 + 1][j * 3 + 1] = 1;
                    matrix[i * 3 + 2][j * 3] = 1;
                }
                else if(grid[i][j] == '\\') {
                    matrix[i * 3][j * 3] = 1;
                    matrix[i * 3 + 1][j * 3 + 1] = 1;
                    matrix[i * 3 + 2][j * 3 + 2] = 1;
                }
            }
        }

        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == 0) {
                    numberofislandsDFS(matrix, i, j);
                    regions++;
                }
            }
        }
        return regions;
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