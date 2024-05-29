// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/?envType=daily-question&envId=2024-05-29

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int numSteps(string s) {
        int res = 0, carry = 0;
        for (auto i = s.size() - 1; i > 0; --i) {
            ++res;
            if (s[i] - '0' + carry == 1) {
                carry = 1;
                ++res;
            }
        }
        return res + carry;
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