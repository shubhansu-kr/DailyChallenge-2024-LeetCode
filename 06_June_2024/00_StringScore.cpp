// https://leetcode.com/problems/score-of-a-string/?envType=daily-question&envId=2024-06-01

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int scoreOfString(string s) {
        int score = 0; 
        for(int i = 1; i < s.length(); ++i) {
            score += abs(s[i] - s[i-1]);
        }
        return score;
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