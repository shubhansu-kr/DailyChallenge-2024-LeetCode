// https://leetcode.com/problems/minimum-string-length-after-removing-substrings/?envType=daily-question&envId=2024-10-07

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
    int minLength(string s) {
        stack<char> st;

        for (char c : s) {
            if (!st.empty() && st.top() == 'A' && c == 'B') {
                st.pop();
            } else if (!st.empty() && st.top() == 'C' && c == 'D') {
                st.pop();
            } else {
                st.push(c);
            }
        }

        return st.size();
    }
};

int main () {
    
    return 0;
}
