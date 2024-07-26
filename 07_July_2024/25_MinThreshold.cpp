// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/?envType=daily-question&envId=2024-07-26

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> graph(n);
        for (const auto& edge : edges) {
            int node1 = edge[0], node2 = edge[1], distance = edge[2];
            graph[node1].emplace_back(node2, distance);
            graph[node2].emplace_back(node1, distance);
        }

        auto get_number_of_neighbors_in_distance = [&](int source) -> int {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> queue;
            queue.emplace(0, source); 
            set<int> visited;

            while (!queue.empty()) {
                auto [distance_to_this_node, cur_node] = queue.top();
                queue.pop();
                if (!visited.count(cur_node)) {
                    visited.insert(cur_node);
                    for (const auto& [neighbor, distance] : graph[cur_node]) {
                        int distance_from_source = distance_to_this_node + distance;
                        if (distance_from_source <= distanceThreshold) { 
                            queue.emplace(distance_from_source, neighbor);
                        }
                    }
                }
            }
            return visited.size() - 1;
        };

        int minimum_number = n;
        int res = -1;

        for (int source = 0; source < n; ++source) {
            int neighbors = get_number_of_neighbors_in_distance(source);
            if (neighbors <= minimum_number) {
                minimum_number = neighbors;
                res = source;
            }
        }

        return res;
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