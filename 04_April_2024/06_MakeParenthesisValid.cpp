// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/?envType=daily-question&envId=2024-04-06

#include <bits/stdc++.h>
using namespace std ;




class Solution {
    // TestCase: ))(( failed
    // Wrong answer: Position of parenthesis mattern, not only the count
public:
    string minRemoveToMakeValid(string s) {
        int l = 0, r = 0;
        for(auto &it: s) {
            if (it == ')') ++r;
        }
        string ans = "";
        for(auto &it: s) {
            if (it == '(') {
                if (r) {
                    ans += it;
                    r--;
                }
                ++l;
            }
            else if (it == ')') {
                if (l) {
                    ans += it;
                    --l;
                }
            }
            else {
                ans += it;
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