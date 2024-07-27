// https://leetcode.com/problems/minimum-cost-to-convert-string-i/?envType=daily-question&envId=2024-07-27

#include <bits/stdc++.h>
using namespace std ;

class Solution {
private:
    static const int N = 26; 
    int graph[N][N];

    void dijkstra(int src, vector<int>& costs){

        priority_queue<pair<int, int>, std::vector<pair<int,int>>, std::greater<pair<int,int>>> pq; // {cost , node}
        costs[src] = 0;
        pq.push({0 , src});

        while (!pq.empty()){
            auto p = pq.top();
            pq.pop();
            int cost = p.first, node = p.second;


            for(int i =0 ;i < N;i++){
                if (graph[node][i] != INT_MAX) {
                    int new_cost = cost + graph[node][i];
                    if (new_cost < costs[i]) {
                        costs[i] = new_cost;
                        pq.push({new_cost, i});
                    }
                }
            }

        }


    }

public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>> all_costs(N, vector<int>(N, INT_MAX));
        for(int i = 0 ; i < N;i++){
            for(int j = 0 ; j < N;j++){
                graph[i][j] = INT_MAX;
            }
        }

        int m = original.size();
        for(int i =0 ; i < m;i++){
            int from = original[i] - 'a';
            int to = changed[i] - 'a';
            graph[from][to] = min(graph[from][to] , cost[i]);
        }

        for(int i =0 ; i < N;i++){
            dijkstra(i , all_costs[i]);
        }

        int n = target.size();
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (source[i] != target[i]) {
                int from = source[i] - 'a';
                int to = target[i] - 'a';
                int conversion_cost = all_costs[from][to];
                if (conversion_cost == INT_MAX) {
                    return -1; 
                }
                ans += conversion_cost;
            }
        }
        cout << ans << endl;
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