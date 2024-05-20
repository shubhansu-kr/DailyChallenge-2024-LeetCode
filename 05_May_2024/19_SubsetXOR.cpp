// https://leetcode.com/problems/sum-of-all-subset-xor-totals/?envType=daily-question&envId=2024-05-19

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return accumulate(begin(nums), end(nums), 0, bit_or<int>()) << (nums.size() - 1);
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