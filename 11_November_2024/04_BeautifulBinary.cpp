// https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/?envType=daily-question&envId=2024-11-05

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
    int minChanges(string s) {
        int res = 0;
        for(int i = 1; i < s.size(); i += 2) {
            res += (s[i] != s[i - 1]) ? 1 : 0;
        }
        return res;
    }
};

int main () {
    
    return 0;
}
