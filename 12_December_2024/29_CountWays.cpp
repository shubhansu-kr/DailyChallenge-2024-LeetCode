// https://leetcode.com/problems/count-ways-to-build-good-strings/?envType=daily-question&envId=2024-12-30

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
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1);
        dp[0] = 1;
        int md = 1e9 + 7;
        for (int i = min(zero, one); i <= high; i++) {
            if(i>=zero){dp[i] = (dp[i] + dp[i - zero]) % md;}
            if(i>=one){dp[i] = (dp[i] + dp[i - one]) % md;}
        }
        int sum = 0;
        for (int i = low; i <= high; i++) {
            sum = (sum + dp[i]) % md;
        }
        return sum;
    }
};

int main () {
    
    return 0;
}
