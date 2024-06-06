#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(int i, int j, int k, int m, vector<vector<vector<vector<int>>>>& dp, const vector<int>& a) {
    if (dp[i][j][k][m] != -1) return dp[i][j][k][m];
    if (k > m) return -(1 << 29); // impossible case
    if (i > j) return 0;
    if (i == j) {
        if (a[i] >= k && a[i] <= m) return 1;
        else return 0;
    }
    int res = 0;
    res = max(res, solve(i+1, j-1, k, m, dp, a));
    if (a[j] >= k)
        res = max(res, solve(i+1, j-1, a[j], m, dp, a) + 1);
    if (a[i] <= m)
        res = max(res, solve(i+1, j-1, k, a[i], dp, a) + 1);
    if (k <= a[j] && a[j] <= a[i] && a[i] <= m) {
        res = max(res, solve(i+1, j-1, a[j], a[i], dp, a) + 2);
    }
    res = max(res, solve(i+1, j, k, m, dp, a));
    if (a[i] >= k)
        res = max(res, solve(i+1, j, a[i], m, dp, a) + 1);
    res = max(res, solve(i, j-1, k, m, dp, a));
    if (a[j] <= m)
        res = max(res, solve(i, j-1, k, a[j], dp, a) + 1);
    return dp[i][j][k][m] = res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(n, vector<vector<int>>(51, vector<int>(51, -1))));

    cout << solve(0, n - 1, 0, 50, dp, a) << endl;

    return 0;
}
