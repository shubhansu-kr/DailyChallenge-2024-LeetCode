// https://leetcode.com/problems/subarray-sums-divisible-by-k/?envType=daily-question&envId=2024-06-09

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> count(k);
        count[0] = 1;
        int prefix = 0, res = 0;
        for (int a : nums)
        {
            prefix = (prefix + a % k + k) % k;
            res += count[prefix]++;
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