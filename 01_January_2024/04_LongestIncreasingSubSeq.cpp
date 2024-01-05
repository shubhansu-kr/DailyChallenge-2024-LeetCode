// https://leetcode.com/problems/longest-increasing-subsequence/?envType=daily-question&envId=2024-01-05

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // dp[i] signifies the size of subsequece if ss ends at index i
        vector<int> dp(n, 1);         
        for (int i = 0; i < n; ++i)
        {    
            for (int j = 0; j < i; ++j)
            {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[j]+1, dp[i]);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main () {
    
    return 0;
}