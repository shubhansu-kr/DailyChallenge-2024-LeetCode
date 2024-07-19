// https://leetcode.com/problems/lucky-numbers-in-a-matrix/?envType=daily-question&envId=2024-07-19

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> lucky;
        for (int i = 0; i < matrix.size(); i++)
        {
            int min = matrix[i][0], col = 0;
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] < min)
                {
                    min = matrix[i][j];
                    col = j;
                }
            }
            int flag = 1;
            for (int i = 0; i < matrix.size(); i++)
            {
                if (min < matrix[i][col])
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                lucky.push_back(min);
            }
        }
        return lucky;
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