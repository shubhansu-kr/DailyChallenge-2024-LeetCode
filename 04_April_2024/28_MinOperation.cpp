// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/?envType=daily-question&envId=2024-04-29

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        for(auto &it: nums) {
            k ^= it;
        }
        return __builtin_popcount(k);
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