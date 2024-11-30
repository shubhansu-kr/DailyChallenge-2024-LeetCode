// https://leetcode.com/problems/valid-arrangement-of-pairs/?envType=daily-question&envId=2024-11-30

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
    void DFS(int start, unordered_map<int, vector<int>> &adj, vector<int> &res){
        while(!adj[start].empty()){
            int node = adj[start].back();
            adj[start].pop_back();
            DFS(node, adj, res);
        }
        res.push_back(start);
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, int> in;
        unordered_map<int, int> out;
        unordered_map<int, vector<int>> adj;
        for(auto pair : pairs){
            out[pair[0]]++;
            in[pair[1]]++;
            adj[pair[0]].push_back(pair[1]);
        }
        int start = -1;
        for(auto node : out){
            if(out[node.first] - in[node.first] == 1){
                start = node.first;
                break;
            }
        }
        if(start == -1) start = pairs[0][0];
        vector<int> res;
        DFS(start, adj, res);
        reverse(res.begin(),res.end());
        vector<vector<int>> ans;
        for(int i = 0; i < res.size() - 1; i++){
            ans.push_back({res[i], res[i+1]});
        }
        return ans;
    }
};

int main () {
    
    return 0;
}
