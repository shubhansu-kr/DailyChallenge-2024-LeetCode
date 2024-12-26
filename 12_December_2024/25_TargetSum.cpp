// https://leetcode.com/problems/target-sum/?envType=daily-question&envId=2024-12-26

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
    int findTargetSumWays(vector<int>& nums, int target) {
        int total_sum = accumulate(nums.begin(), nums.end(), 0);  

        if ((target + total_sum) % 2 != 0 || abs(target) > total_sum) {
            return 0;
        }

        int subset_sum = (target + total_sum) / 2;

        vector<int> dp(subset_sum + 1, 0);
        dp[0] = 1;  

        for (int num : nums) {
            for (int i = subset_sum; i >= num; --i) {
                dp[i] += dp[i - num];
            }
        }

        return dp[subset_sum];
    }
};

int main () {
    
    return 0;
}
