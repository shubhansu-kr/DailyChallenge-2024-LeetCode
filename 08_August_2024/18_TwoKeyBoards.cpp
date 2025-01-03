// https://leetcode.com/problems/2-keys-keyboard/?envType=daily-question&envId=2024-08-19

#include <bits/stdc++.h>
using namespace std ;

class Solution1 {
    // Recursion: Memoisation 
public:
    int solve(int &n, int cp, int len, vector<vector<int>> &dp) {
        if (len > n) return 10e6;
        if (len == n) return 0;

        if(dp[cp][len] != -1) return dp[cp][len];

        int copyCurrent = INT_MAX;
        if (cp != len) {
            copyCurrent = 1 + solve(n, len, len, dp);
        }
        int pasteCurrent = INT_MAX;
        if (cp) {
            pasteCurrent = 1 + solve(n, cp, len+cp, dp);
        }

        return dp[cp][len] = min(copyCurrent, pasteCurrent);
    }

    int minSteps(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(n, 0, 1, dp);
    }
};

class Solution {
    // BruteForce : Recursion
public:
    int solve(int n, int cp, int len) {
        if (len > n) return 10e6;
        if (len == n) return 0;

        int copyCurrent = INT_MAX;
        if (cp != len) {
            copyCurrent = 1 + solve(n, len, len);
        }
        int pasteCurrent = INT_MAX;
        if (cp) {
            pasteCurrent = 1 + solve(n, cp, len+cp);
        }

        return min(copyCurrent, pasteCurrent);
    }

    int minSteps(int n) {
        return solve(n, 0, 1);
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