// https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/?envType=daily-question&envId=2024-07-30

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int minimumDeletions(string s) {
        int deletions = 0;
        stack<char> stk;
        
        for (char c : s) {
            if (c == 'b') {
                stk.push(c);
            } else if (c == 'a') {
                if (!stk.empty()) {
                    deletions++;
                    stk.pop();
                }
            }
        }
        
        return deletions;
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