// https://leetcode.com/problems/path-with-maximum-probability/?envType=daily-question&envId=2024-09-01

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> g(n);
        for (int i = 0; i < edges.size(); i++)
        {
            g[edges[i][0]].push_back({edges[i][1], succProb[i]});
            g[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        vector<int> seen(n, 0);

        priority_queue<pair<double, int>> q;
        q.push({(double)1.0, start});

        vector<double> mx(n, (double)0.0);
        mx[start] = 1.0;

        while (!q.empty())
        {
            auto top = q.top();
            q.pop();
            double proba = top.first;
            int node = top.second;
            if (!seen[node])
            {
                seen[node]++;
                for (auto &to : g[node])
                {
                    if (mx[to.first] < to.second * proba)
                    {
                        mx[to.first] = to.second * proba;
                        q.push({mx[to.first], to.first});
                    }
                }
            }
        }
        return mx[end];
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
