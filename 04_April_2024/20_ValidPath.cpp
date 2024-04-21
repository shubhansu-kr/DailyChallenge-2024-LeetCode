// https://leetcode.com/problems/find-if-path-exists-in-graph/?envType=daily-question&envId=2024-04-21

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<vector<int>> createAdjacencyMatrix(int n, vector<vector<int>> &edges) {
        vector<vector<int>> graph(n, vector<int> (n, 0));
        for(auto &v: edges) {
            graph[v[0]][v[1]] = 1;
            graph[v[1]][v[1]] = 1;
        }
        return graph;
    }

    vector<vector<int>> createAdjacencyList(int n, vector<vector<int>> &edges){
        vector<vector<int>> graph(n);
        for(auto &v: edges) {
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }
        return graph;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination) return true;

        vector<vector<int>> graph = createAdjacencyList(n, edges);

        queue<int> q;
        vector<bool> visited(n, false);

        q.push(source);
        visited[source] = true;

        while(q.size()) {
            int u = q.front();
            q.pop();

            for(auto &it: graph[u]) {
                if (!visited[it]) {
                    if (it == destination) return true;
                    visited[it] = true;
                    q.push(it);
                }
            }
        }

        return visited[destination];
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