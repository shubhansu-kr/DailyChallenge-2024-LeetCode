// https://leetcode.com/problems/maximum-total-importance-of-roads/?envType=daily-question&envId=2024-06-28

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> freq(n, 0);
        for (int i = 0; i < roads.size(); ++i)
        {
            ++freq[roads[i][0]];
            ++freq[roads[i][1]];
        }
        vector<pair<int, int>> p(n);
        for (int i = 0; i < n; ++i)
        {
            p[i].first = freq[i];
            p[i].second = i;
        }
        sort(p.rbegin(), p.rend());
        for (int i = 0; i < n; ++i)
        {
            freq[p[i].second] = n - i;
        }
        long long imp = 0;
        for (int i = 0; i < roads.size(); ++i)
        {
            imp += (freq[roads[i][0]] + freq[roads[i][1]]);
        }
        return imp;
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