// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/?envType=daily-question&envId=2024-10-09

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
    int minAddToMakeValid(string s) {
        int ans = 0, bal = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            s[i] == '(' ? ++bal : --bal;
            if (bal == -1)
                ++ans, ++bal;
        }
        return bal + ans;
    }
};

int main () {
    
    return 0;
}
