// https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/?envType=daily-question&envId=2024-06-29

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans(n), directChild(n);
        for(auto& e: edges) 
            directChild[e[0]].push_back(e[1]);
        for(int i = 0; i < n; i++)
            dfs(i, i, ans, directChild);
        return ans;
    }
    void dfs(int x, int curr, vector<vector<int>>& ans, vector<vector<int>>& directChild) {
        for (auto& ch: directChild[curr]) 
            if(ans[ch].size() == 0 || ans[ch].back() != x) {
                ans[ch].push_back(x);
                dfs(x, ch, ans, directChild);
            }
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