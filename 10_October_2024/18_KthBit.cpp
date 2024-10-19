// https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/?envType=daily-question&envId=2024-10-19

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
    char findKthBit(int n, int k) {
        if (n == 1) {
            return '0';
        }
        int len = (1 << n) - 1;
        int mid = (len / 2) + 1;

        if (k < mid) {
            return findKthBit(n - 1, k);
        }

        else if (k == mid) {
            return '1';
        }
        else {
            char bit = findKthBit(n - 1, len - k + 1);

            return bit == '0' ? '1' : '0';
        }
        
    }
};

int main () {
    
    return 0;
}
