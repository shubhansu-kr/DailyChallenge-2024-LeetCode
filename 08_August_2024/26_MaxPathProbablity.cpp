// https://leetcode.com/problems/path-with-maximum-probability/?envType=daily-question&envId=2024-08-27

#include <bits/stdc++.h>
using namespace std ;


class Solution {
    // WA
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<double>> graph(n, vector<double> (n));
        for(int i = 0; i < edges.size(); ++i) {
            graph[edges[i][0]][edges[i][1]] = succProb[i];
            graph[edges[i][1]][edges[i][0]] = succProb[i];
        }

        vector<double> pb(n);
        queue<int> q;
        q.push(start_node);
        pb[start_node] = 1;
        while(q.size()) {
            int curr = q.front();
            q.pop();
            for(int i = 0; i < n; ++i) {
                if (graph[curr][i] && i != curr) {
                    if (!pb[i]) {
                        q.push(i);
                    }
                    pb[i] = max(pb[i], pb[curr]*graph[curr][i]);
                }
            }
        }
        return pb[end_node];
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