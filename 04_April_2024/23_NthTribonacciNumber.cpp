// https://leetcode.com/problems/n-th-tribonacci-number/?envType=daily-question&envId=2024-04-24

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int tribonacci(int n) {
        if (n < 3) return n != 0;
        int prev0 = 0, prev1 = 1, prev2 =1;

        for (int i = 3; i < n+1; ++i)
        {
            int temp;
            temp = prev0+prev1+prev2;

            prev0 = prev1;
            prev1 = prev2;
            prev2 = temp;
        }

        return prev2;
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