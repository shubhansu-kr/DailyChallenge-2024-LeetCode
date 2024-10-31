// https://leetcode.com/problems/minimum-total-distance-traveled/?envType=daily-question&envId=2024-10-31

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
    long long solve(int i, int j, int remainingCapacity, vector<int>& robots, vector<vector<int>>& factory, vector<vector<vector<long long>>>& dp) {
        if (i >= robots.size()) { return 0; }
        if (j >= factory.size()) { return 1e15; }
        if (dp[i][j][remainingCapacity] != -1) { return dp[i][j][remainingCapacity]; }

        long long currCost = 1e15;
        if (remainingCapacity > 0) {
            currCost = solve(i + 1, j, remainingCapacity - 1, robots, factory, dp) + abs(robots[i] - factory[j][0]);
        }

        long long skipCost=1e15;
        if(j+1<factory.size()) skipCost = solve(i, j + 1, factory[j + 1][1], robots, factory, dp);

        return dp[i][j][remainingCapacity] = min(currCost, skipCost);
    }

    long long minimumTotalDistance(vector<int>& robots, vector<vector<int>>& factory) {
        sort(robots.begin(), robots.end());
        sort(factory.begin(), factory.end());

        int n = robots.size();
        int m = factory.size();

        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(m, vector<long long>(101, -1)));

        return solve(0, 0, factory[0][1], robots, factory, dp);
    }
};

int main () {
    
    return 0;
}
