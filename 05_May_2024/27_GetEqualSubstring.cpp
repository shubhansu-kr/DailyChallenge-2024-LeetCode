// https://leetcode.com/problems/get-equal-substrings-within-budget/?envType=daily-question&envId=2024-05-28

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int equalSubstring(string s, string t, int k) {
        int n = s.length(), i = 0, j;
        for (j = 0; j < n; ++j) {
            if ((k -= abs(s[j] - t[j])) < 0)
                k += abs(s[i] - t[i++]);
        }
        return j - i;
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