// https://leetcode.com/problems/maximal-rectangle/?envType=daily-question&envId=2024-04-13

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(!size(matrix)) return 0;
        int ans = 0, m = size(matrix), n = size(matrix[0]);
        vector<vector<short>> dp(m+1, vector<short>(n+1)), up(m, vector<short>(n,1)), down(up);
        for(int i = m-1; ~i; i--) 
            for(int j = n-1; ~j; j--) 
                dp[i][j] = matrix[i][j] == '1' ? dp[i][j+1] + 1 : 0;
        
        stack<int> s;
        for(int j = 0; j < n; j++) {
            s = stack<int>();
            for(int i = 0; i < m; i++) {
                while(size(s) && dp[s.top()][j] >= dp[i][j]) s.pop();
                up[i][j] = i - (size(s) ? s.top() : -1);
                s.push(i);
            }
            s = stack<int>();
            for(int i = m-1; ~i; i--) {
                while(size(s) && dp[s.top()][j] >= dp[i][j]) s.pop();
                down[i][j] = (size(s) ? s.top() : m) - i;
                s.push(i);
            }            
        }

        for(int i = 0; i < m; i++) 
            for(int j = 0; j < n; j++) 
                ans = max(ans, dp[i][j] * (up[i][j]+down[i][j]-1));
                    
        return ans;
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