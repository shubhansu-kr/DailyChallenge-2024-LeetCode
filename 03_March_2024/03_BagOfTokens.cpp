// https://leetcode.com/problems/bag-of-tokens/?envType=daily-question&envId=2024-03-04

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int res = 0, points = 0, i = 0, j = tokens.size() - 1;
        while (i <= j) {
            if (power >= tokens[i]) {
                power -= tokens[i++];
                res = max(res, ++points);
            } else if (points > 0) {
                points--;
                power += tokens[j--];
            } else {
                break;
            }
        }
        return res;
    }
};

int main () {
    
    return 0;
}