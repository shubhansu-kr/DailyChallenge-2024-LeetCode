// 

#include <bits/stdc++.h>
using namespace std ;

int getMinCost(int N, vector<int> A) {
    vector<int> dp(N, INT_MAX);
    dp[0] = 0;

    for (int i = 0; i < N; ++i) {
        if (i + 1 < N) {
            dp[i + 1] = min(dp[i + 1], dp[i] + 1);
        }

        for (int j = i + 1; j < N; ++j) {
            if (A[j] % A[i] == 0) {
                if (dp[i]+ A[i] + 1 < dp[j]){
                    dp[j] = dp[i] + A[i] + 1;
                }
                A[j]++; 
            }
        }
    }

    return dp[N-1];
}


auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

int main () {
    int N = 5; 
    vector<int> A = {2, 4, 7, 11, 13, 17, 19, 23, 27, 25};

    cout << getMinCost(N, A);
    return 0;
}