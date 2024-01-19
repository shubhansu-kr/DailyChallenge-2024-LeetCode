// https://leetcode.com/problems/minimum-falling-path-sum/?envType=daily-question&envId=2024-01-19

#include <bits/stdc++.h>
using namespace std ;

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        for (auto i = 1; i < matrix.size(); ++i)
            for (auto j = 0; j < matrix.size(); ++j)
                matrix[i][j] += min({matrix[i - 1][j], matrix[i - 1][max(0, j - 1)], matrix[i - 1][min((int)matrix.size() - 1, j + 1)]});
        return *min_element(begin(matrix[matrix.size() - 1]), end(matrix[matrix.size() - 1]));
    }
};

int main () {
    
    return 0;
}