// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/?envType=daily-question&envId=2024-04-04

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int maxDepth(string s) {
        int dep = 0;
        int ans = INT_MIN;
        for(auto &it: s){
            if (it == '(') {
                ++dep;
            }
            else if (it == ')') {
                ans = max(ans, dep);
                --dep;
            }
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