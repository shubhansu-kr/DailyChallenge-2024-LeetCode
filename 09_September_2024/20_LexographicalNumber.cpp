// https://leetcode.com/problems/lexicographical-numbers/?envType=daily-question&envId=2024-09-21

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
    void solve(int i, int n, vector<int>& v) {
        if (i > n)
            return;
        v.push_back(i);

        for (int j = 0; j <= 9; j++) {
            int ans = i * 10 + j;
            solve(ans, n, v);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for (int i = 1; i <= 9; i++) {
            solve(i, n, ans);
        }
        return ans;
    }
};

int main () {
    
    return 0;
}
