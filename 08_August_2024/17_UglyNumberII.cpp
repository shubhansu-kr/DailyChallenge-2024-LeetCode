// https://leetcode.com/problems/ugly-number-ii/?envType=daily-question&envId=2024-08-18

#include <bits/stdc++.h>
using namespace std ;

class Solution {
    // bruteForce : TLE 
public:
    void solve(int k, vector<bool> &dp) {
        if (k >= sz || dp[k]) return;

        dp[k] = true;
        solve(k*2, dp);
        solve(k*3, dp);
        solve(k*5, dp);
    }

    int nthUglyNumber(int n) {
        int sz = INT_MAX;
        vector<bool> dp(sz, false);

        queue<int> q;
        q.push(2);
        q.push(3);
        q.push(5);

        while(q.size()){
            int tp = q.front();
            q.pop();
            if (tp >= sz) break;
            if (dp[tp]) continue;

            dp[tp] = true;
            int twice = tp * 2, thrice = tp * 3, fifth = tp *5;
            q.push(twice);
            q.push(thrice);
            q.push(fifth);
        }

        vector<int> uglyNumbers;
        for(int i = 0; i < sz; ++i) {
            if (dp[i]) uglyNumbers.emplace_back(i);
        }
        return uglyNumbers.size();
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

int main () {
    Solution obj;
    cout << obj.nthUglyNumber(1);
    return 0;
}