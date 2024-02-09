// https://leetcode.com/problems/largest-divisible-subset/description/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
         sort(nums.begin(), nums.end());
        int n = nums.size();
        // dp[i] signifies the size of subsequece if ss ends at index i
        vector<int> dp(n, 1), hash(n);
        for (int i = 0; i < n; ++i){hash[i] = i ;}
        int maxIndex = 0, maxVal = INT_MIN;
        for (int i = 0; i < n; ++i)
        {    
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j]+1) {
                    hash[i] = j ;
                    dp[i] = dp[j]+1;
                    if (maxVal < dp[i]) {
                        maxVal = dp[i];
                        maxIndex = i;
                    }
                } 
            }
        }
        vector<int> LDS;
        while(true) {
            LDS.emplace_back(nums[maxIndex]);
            if (maxIndex == hash[maxIndex]) break;
            maxIndex = hash[maxIndex];
        };
        
        reverse(LDS.begin(), LDS.end()); 
        return LDS;
    }
};

int main () {
    
    return 0;
}