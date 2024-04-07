// https://leetcode.com/problems/valid-parenthesis-string/?envType=daily-question&envId=2024-04-07  

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool solve(string &s, int ct, int i) {
        if (i >= s.size()){
            return ct == 0;
        }

        if (s[i] == '('){
            return solve(s, ct+1, i+1);
        }
        else if (s[i] == ')'){
            return (ct > 0) ? solve(s, ct-1, i+1) : false;
        }
        else {
            bool left = false, right = false, mid = false;
            left = solve(s, ct+1, i+1);
            if (left) return true;
            mid = solve(s, ct, i+1);
            if (mid) return true;
            if (ct > 0) right = solve(s, ct-1, i+1);
            return left || mid || right;
        }
        
        return false;
    }
    bool checkValidString(string s) {
        int ct = 0;

        return solve(s, ct, 0);        
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