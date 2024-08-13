// https://leetcode.com/problems/combination-sum-ii/?envType=daily-question&envId=2024-08-13

#include <bits/stdc++.h>
using namespace std ;

class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> v;
        comb(candidates, target, res, v);
        return res;
    }

    void comb(vector<int> &candidates, int target, vector<vector<int>> &res, vector<int> &v, int i = 0)
    {
        if (target == 0)
        {
            res.push_back(v);
            return;
        }
        for (int j = i; j < candidates.size(); ++j)
        {
            if (candidates[j] > target)
            {
                break;
            }
            if (j > i && candidates[j] == candidates[j - 1])
            {
                // Don't pick 
                continue;
            }
            else
            {
                // Pick
                v.push_back(candidates[j]);
                comb(candidates, target - candidates[j], res, v, j + 1);
                v.pop_back();
            }
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