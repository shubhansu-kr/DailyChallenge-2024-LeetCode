// https://leetcode.com/problems/maximum-matrix-sum/?envType=daily-question&envId=2024-11-24

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
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long ans = 0;
        int c0 = 0, cn = 0;
        int minn = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] < 0)
                    cn++;
                else if (matrix[i][j] == 0)
                    c0++;
                ans += abs(matrix[i][j]);
                minn = min(minn, abs(matrix[i][j]));
            }
        }
        if ((cn % 2 == 0) || c0 > 0)
        {
            return ans;
        }
        return ans - 2 * minn;
    }
};

int main () {
    
    return 0;
}
