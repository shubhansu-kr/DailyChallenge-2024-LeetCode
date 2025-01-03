// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/?envType=daily-question&envId=2024-08-29

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool isValid(vector<int>&pos1, vector<int>&pos2)
    {
        if (pos1[0] == pos2[0]) return true;
        if (pos1[1] == pos2[1]) return true;
        return false;
    }
    void dfs(vector<vector<int>>&stones, vector<bool>&visited, int currIdx)
    {
        visited[currIdx] = true;
        for (int i = 0; i < stones.size(); i++)
        {
            if (visited[i]) continue;
            if (isValid(stones[i], stones[currIdx]))  dfs(stones, visited, i);
        }
    }
    int removeStones(vector<vector<int>>& stones)
    {
        int n = stones.size();
        vector<bool>visited(n, false);
        int componentCount = 0;
        for (int i = 0; i < n; i++)
        {
            if (visited[i]) continue;
            dfs(stones, visited, i);
            componentCount++;
        }
        return (n - componentCount); 
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