// https://leetcode.com/problems/partition-array-for-maximum-sum/?envType=daily-question&envId=2024-02-03   

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int N = arr.size();
        vector<int> dp(N + 1);
        for (int i = 1; i <= N; ++i) {
            int curMax = 0, best = 0;
            for (int k = 1; k <= k && i - k >= 0; ++k) {
                curMax = max(curMax, arr[i - k]);
                best = max(best, dp[i - k] + curMax * k);
            }
            dp[i] = best; 
        }
        return dp[N];
    }
};

int main () {
    
    return 0;
}