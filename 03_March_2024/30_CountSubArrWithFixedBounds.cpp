// https://leetcode.com/problems/count-subarrays-with-fixed-bounds/?envType=daily-question&envId=2024-03-31

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long res = 0, jbad = -1, jmin = -1, jmax = -1, n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] < minK || nums[i] > maxK) jbad = i;
            if (nums[i] == minK) jmin = i;
            if (nums[i] == maxK) jmax = i;
            res += max(0L, min(jmin, jmax) - jbad);
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