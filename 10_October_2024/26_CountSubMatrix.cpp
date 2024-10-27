// https://leetcode.com/problems/count-square-submatrices-with-all-ones/?envType=daily-question&envId=2024-10-27

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
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> res(n,vector<int>(m,0));
        int ans = 0;
        for(int i = 0 ; i < n ;i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j]){
                    if(i==0 || j == 0){
                        res[i][j] = matrix[i][j];
                        ans += res[i][j];
                    }
                    else {
                        res[i][j] = min(res[i-1][j],min(res[i][j-1],res[i-1][j-1])) + 1;
                        ans += res[i][j];
                    }

                }else{
                    res[i][j] = 0;
                    ans += res[i][j];
                }
            }
        }
        return ans;
    }
};

int main () {
    
    return 0;
}
