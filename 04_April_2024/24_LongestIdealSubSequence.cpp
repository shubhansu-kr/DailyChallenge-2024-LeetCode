// https://leetcode.com/problems/longest-ideal-subsequence/?envType=daily-question&envId=2024-04-25

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int longestIdealString(string s, int k) {
        int DP[26] = {0}, ans = 1;
        
        for (char &ch: s) {
            int i = ch - 'a';
            DP[i] = DP[i] + 1;
            
            for (int j = max(0, i - k); j <= min(25, i + k); j++)
                if (j != i)
                    DP[i] = max(DP[i], DP[j] + 1);
            
            ans = max(ans, DP[i]);
        }
        
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

int main () {
    
    return 0;
}