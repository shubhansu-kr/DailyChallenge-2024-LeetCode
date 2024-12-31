// https://leetcode.com/problems/minimum-cost-for-tickets/?envType=daily-question&envId=2024-12-31

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
    int mincostTickets(vector<int>& days, vector<int>& costs) {
         unordered_set<int> travel(begin(days), end(days));
        int dp[30] = {};
        for (int i = days.front(); i <= days.back(); ++i)
        {
            if (travel.find(i) == travel.end()) dp[i % 30] = dp[(i - 1) % 30];
            else dp[i % 30] = min({dp[(i - 1) % 30] + costs[0], dp[max(0, i - 7) % 30] + costs[1], dp[max(0, i - 30) % 30] + costs[2]});
        }
        return dp[days.back() % 30];
    }
};

int main () {
    
    return 0;
}
