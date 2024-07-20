// https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/?envType=daily-question&envId=2024-07-20

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>> res(rowSum.size(), vector<int>(colSum.size(), 0));
        for (int i = 0; i < rowSum.size(); i++)
        {
            for (int j = 0; j < colSum.size(); j++)
            {
                int x = min(rowSum[i], colSum[j]);
                res[i][j] = x;
                rowSum[i] -= x;
                colSum[j] -= x;
            }
        }
        return res;
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