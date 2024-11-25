// https://leetcode.com/problems/sliding-puzzle/?envType=daily-question&envId=2024-11-25

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

    vector<pair<int, int>> cords = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int solve(vector<vector<int>>&board, int i, int j, int &moves, int parenti, int parentj){
        if(board[0][0] == 1 && board[0][1] == 2 && board[0][2] == 3 && board[1][0] == 4 && board[1][1] == 5 && board[1][2] == 0) return 0;
        if(moves == 20) return 1e9;

        int ans = INT_MAX;
        for(int x = 0; x < 4; x++){
            int newx = i + cords[x].first;
            int newy = j + cords[x].second;
            if(newx == parenti && newy == parentj) continue;
            if(newx >= 0 && newy >= 0 && newy < 3 && newx < 2){
                swap(board[i][j], board[newx][newy]);
                moves++;
                ans = min(ans, 1 + solve(board, newx, newy, moves, i, j));
                moves--;
                swap(board[i][j], board[newx][newy]);
            }
        }
        return ans;
    }

    int slidingPuzzle(vector<vector<int>>& board) {
        int ans = -1;
        int moves = 0;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 3; j++){
                if(board[i][j] == 0){
                    ans = solve(board, i, j, moves, -1, -1);
                }
            }
        }
        return ans > 1e9 ? -1 : ans;
    }
};

int main () {
    
    return 0;
}
