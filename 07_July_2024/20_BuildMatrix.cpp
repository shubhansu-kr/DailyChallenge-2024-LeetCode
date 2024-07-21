// https://leetcode.com/problems/build-a-matrix-with-conditions/?envType=daily-question&envId=2024-07-21

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> childRow(k+1);
        vector<vector<int>> childCol(k+1);
        for(int i=0; i<rowConditions.size(); i++){
            childRow[rowConditions[i][0]].push_back(rowConditions[i][1]);
        }
        for(int i=0; i<colConditions.size(); i++){
            childCol[colConditions[i][0]].push_back(colConditions[i][1]);
        }
        vector<bool> isStillIterating(k+1, false);
        vector<int> resRow(k+1, 0);
        vector<int> resCol(k+1,0);
        vector<bool> isRowVis(k+1, false);
        vector<bool> isColVis(k+1, false);
        int order = k-1;
        for(int i=1; i<=k;i++){
            if(!dfs(childRow, isRowVis, isStillIterating, i, resRow, order)){
                vector<vector<int>> res(0);
                return res;
            }
        }
        order = k-1;
        for(int i=1; i<=k; i++){
            if(!dfs(childCol, isColVis, isStillIterating, i, resCol, order)){
                return vector<vector<int>>(0);
            }
        }

        vector<vector<int>> res(k, vector<int>(k,0));
        for(int i=1; i<=k; i++){
            res[resRow[i]][resCol[i]] = i;
        }
        return res;
    }

    bool dfs(vector<vector<int>>& child, vector<bool>& isVis, vector<bool>& isStillIterating, int root, vector<int>& res, int& order){
        if(isStillIterating[root]) return false;
        if(isVis[root]) return true;
        isVis[root] = true;
        isStillIterating[root] = true;

        for(auto c: child[root]){
            bool dfsC = dfs(child, isVis, isStillIterating, c, res, order);
            if(!dfsC){
                isStillIterating[root] = false;
                return false;
            }
        }

        res[root] = order;
        order--;
        isStillIterating[root] = false;
        return true;
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