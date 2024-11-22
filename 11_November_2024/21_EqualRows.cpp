// https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/?envType=daily-question&envId=2024-11-22

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
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        map<string, int> mp;
        for (auto i : matrix) {
            string res = "";
            for (auto j : i) {
                res += to_string(j);
            }
            if(res[0]!='0'){
                for (int k = 0; k < res.size(); k++) {
                    if (res[k] == '0') {
                        res[k] = '1';
                    } else {
                        res[k] = '0';
                    }
                }
            }
            if (mp.count(res)) {
                mp[res]++;
            } else {
                mp[res]++;
            }
        }
        int ans = 0;
        for (auto [x, y] : mp) {
            ans = max(ans, y);
        }
        return ans;
    }
};

int main () {
    
    return 0;
}
