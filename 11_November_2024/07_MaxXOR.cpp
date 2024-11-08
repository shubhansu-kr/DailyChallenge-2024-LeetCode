// https://leetcode.com/problems/maximum-xor-for-each-query/?envType=daily-question&envId=2024-11-08

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
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int temp = nums[0];
        int max = (1 << maximumBit) - 1;
        nums[0] = temp ^ max;
        for (int i = 1; i < nums.size(); i++)
        {
            temp = temp ^ nums[i];
            nums[i] = temp ^ max;
        }
        reverse(nums.begin(), nums.end());
        return nums;
    }
};

int main () {
    
    return 0;
}
