// https://leetcode.com/problems/longest-common-subsequence/?envType=daily-question&envId=2024-01-25

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        if (m == 0 || n == 0) return 0;

        vector<int> temp(n+1);
        
        for(int i = 1; i <= m; ++i) {
            vector<int> curr(n+1);
            for(int j = 1; j <= n; ++j) {
                if (text1[i-1] == text2[j-1]) curr[j] = 1 + temp[j-1];
                else curr[j] = max(temp[j], curr[j-1]);
            }
            temp = curr;
        }

        return temp[n];
    }
};

int main () {
    
    return 0;
}