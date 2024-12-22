// https://leetcode.com/problems/find-building-where-alice-and-bob-can-meet/?envType=daily-question&envId=2024-12-22

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
    vector<int> leftmostBuildingQueries(const vector<int>& heights, vector<vector<int>>& queries) {
        const int N = heights.size();

        for (auto& q : queries)
            if (q[0] > q[1])
                swap(q[0], q[1]);
        vector<int> qidx(queries.size());
        iota(qidx.begin(), qidx.end(), 0);
        sort(qidx.begin(), qidx.end(), 
                [&queries](int a, int b) { return queries[a][1] < queries[b][1]; });

        vector<int> res(queries.size(), -1);

        vector<int> stk_desc_bw_pos;
        for (int i = N - 1; ~i; --i) {
            while (!qidx.empty()) { 
                int qi = qidx.back();
                if (queries[qi][1] < i) break;
                qidx.pop_back();

                int a = queries[qi][0];
                int b = queries[qi][1];
                if (a == b || heights[b] > heights[a]) {
                    res[qi] = b;
                    continue;
                }

                auto it = upper_bound(
                    stk_desc_bw_pos.rbegin(), stk_desc_bw_pos.rend(), heights[a],
                    [&heights](int look_for_h, int pos) { return look_for_h < heights[pos]; });
                res[qi] = it == stk_desc_bw_pos.rend() ? -1 : *it;
            }

            while (!stk_desc_bw_pos.empty() && heights[stk_desc_bw_pos.back()] <= heights[i])
                stk_desc_bw_pos.pop_back();
            stk_desc_bw_pos.push_back(i);
        }

        return res;
    }
};

int main () {
    
    return 0;
}
