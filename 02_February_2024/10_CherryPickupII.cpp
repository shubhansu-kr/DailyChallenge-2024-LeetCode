// https://leetcode.com/problems/cherry-pickup-ii/?envType=daily-question&envId=2024-02-11

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> cp(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == j)
                {
                    cp[i][j] = grid[m - 1][j];
                }
                else
                {
                    cp[i][j] = grid[m - 1][j] + grid[m - 1][i];
                }
            }
        }

        // Tabulation starts (from m-2 to 0)
        for (int i = m - 2; i >= 0; --i)
        {
            vector<vector<int>> temp(n, vector<int>(n));
            for (int j1 = 0; j1 < n; ++j1)
            {
                for (int j2 = 0; j2 < n; ++j2)
                {
                    int subMax = INT_MIN;
                    // Loop through possibilites
                    for (int x = -1; x < 2; ++x)
                    {
                        for (int y = -1; y < 2; ++y)
                        {
                            // Check for common cell
                            int val = 0;
                            if (j1 == j2)
                                val = grid[i][j1];
                            else
                                val = grid[i][j1] + grid[i][j2];
                            //
                            if (j1 + x >= 0 && j2 + y >= 0 && j1 + x < n && j2 + y < n)
                                val += cp[j1 + x][j2 + y];
                            else
                                val += -1e5;
                            subMax = max(subMax, val);
                        }
                    }
                    temp[j1][j2] = subMax;
                }
            }
            cp = temp;
        }
        return cp[0][n - 1];
    }
};

int main () {
    
    return 0;
}