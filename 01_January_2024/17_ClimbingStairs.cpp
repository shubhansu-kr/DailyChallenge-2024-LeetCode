// https://leetcode.com/problems/climbing-stairs/?envType=daily-question&envId=2024-01-18

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int climbStairs(int n) {
        int prev = 1, prev1 = 1, temp;
        for (int i = 2; i <= n; ++i)
        {
            temp = prev + prev1;
            prev1 = prev;
            prev = temp;
        }
        return prev;
    }
};

int main () {
    
    return 0;
}