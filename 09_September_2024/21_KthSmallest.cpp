// https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/solutions/?envType=daily-question&envId=2024-09-22

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
    long countSteps(long curr, long n) {
        long steps = 0;
        long first = curr, last = curr;

        while (first <= n) {
            steps += min(n + 1, last + 1) - first;
            first *= 10;
            last = last * 10 + 9;
        }

        return steps;
    }

    int findKthNumber(int n, int k) {
        int curr = 1;  
        k--;           

        while (k > 0) {
            long steps = countSteps(curr, n);
            if (steps <= k) {
                curr++;
                k -= steps;  
            } else {
                curr *= 10;
                k--;  
            }
        }

        return curr;
    }
};


int main () {
    
    return 0;
}
