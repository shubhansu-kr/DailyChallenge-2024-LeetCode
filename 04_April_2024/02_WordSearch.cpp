// https://leetcode.com/problems/word-search/?envType=daily-question&envId=2024-04-03

#include <bits/stdc++.h>
using namespace std ;

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        for (unsigned int i = 0; i < board.size(); i++)
            for (unsigned int j = 0; j < board[0].size(); j++)
                if (dfs(board, i, j, word))
                    return true;
        return false;
    }

    bool dfs(vector<vector<char>> &board, int i, int j, string &word)
    {
        if (!word.size())
            return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[0])
            return false;
        char c = board[i][j];
        board[i][j] = '*';
        string s = word.substr(1);
        bool ret = dfs(board, i - 1, j, s) || dfs(board, i + 1, j, s) || dfs(board, i, j - 1, s) || dfs(board, i, j + 1, s);
        board[i][j] = c;
        return ret;
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