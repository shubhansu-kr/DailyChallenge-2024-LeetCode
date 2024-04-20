// https://leetcode.com/problems/find-all-farm-of-farmland/?envType=daily-question&envId=2024-04-20

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    pair<int, int> traverse(vector<vector<int>> &land, vector<vector<bool>> &vis, int &r1, int &c1) {
        int m = land.size(), n = land[0].size();

        pair<int, int> p;
        int r2 = r1, c2 = c1;

        for(; r2 < m; ++r2){ if (!land[r2][c1]) break; }
        for(; c2 < n; ++c2){ if (!land[r1][c2]) break; }

        for(int i = r1; i < r2; ++i) {
            for(int j = c1; j < c2; ++j) {
                vis[i][j] = true;
            }
        }

        p.first = r2-1;
        p.second = c2-1;

        return p;
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size(), n = land[0].size();

        vector<vector<int>> farm;

        vector<vector<bool>> visited(m, vector<bool>(n));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if (land[i][j] && !visited[i][j]) {
                    vector<int> group(4, -1);

                    pair<int, int> p = traverse(land, visited, i, j);

                    group[0] = i;
                    group[1] = j;
                    group[2] = p.first;
                    group[3] = p.second;

                    farm.push_back(group);
                }
            }
        }

        return farm;
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