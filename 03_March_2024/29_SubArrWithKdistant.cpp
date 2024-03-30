// https://leetcode.com/problems/subarrays-with-k-different-integers/?envType=daily-question&envId=2024-03-30

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int cnt[20001] = {}, res = 0, sz = nums.size();
        for (int l = 0, m = 0, r = 0; r < sz; ++r) {
            if (++cnt[nums[r]] == 1)
                if (--k < 0) {
                    cnt[nums[m++]] = 0;
                    l = m;
                }
            if (k <= 0) {
                while (cnt[nums[m]] > 1)
                    --cnt[nums[m++]];
                res += m - l + 1;   
            }
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