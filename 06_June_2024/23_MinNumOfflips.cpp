// https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/?envType=daily-question&envId=2024-06-24

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int K, int res = 0, int flips = 0) {
        for (auto i = 0; i < nums.size(); ++i) {
            if (nums[i] == flips % 2) {
            if (i > nums.size() - K) return -1;
            ++res, ++flips, nums[i] -= 2;
            }
            if (i >= K - 1 && nums[i - K + 1] < 0) --flips, nums[i - K + 1] += 2;
        }
        return res;
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