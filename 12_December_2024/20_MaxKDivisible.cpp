// https://leetcode.com/problems/maximum-number-of-k-divisible-components/?envType=daily-question&envId=2024-12-21

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
    unordered_map<int, vector<int>> adj;
    int comp = 0;
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k)
     {
      for(auto& edge : edges){
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
      }  
      dfs(0, -1, values, k);
      return comp;
    }
    private:
    int dfs(int node, int parent, vector<int>& values, int k){
        int sum = values[node];

        for(int neighbor : adj[node]){
            if(neighbor != parent){
                sum += dfs(neighbor, node, values, k);
            }
        }
        if(sum % k == 0){
            comp++;
            return 0;
        }
        return sum % k;
    }
};

int main () {
    
    return 0;
}
