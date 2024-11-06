// https://leetcode.com/problems/find-if-array-can-be-sorted/?envType=daily-question&envId=2024-11-06

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
    bool canSortArray(vector<int>& nums) {
        vector<pair<int, int>> bits;
        int x = 0;
        for(int i : nums) bits.push_back({i, x}), x++;
        sort(bits.begin(), bits.end());
        for(int i = 0; i < bits.size(); i++)
            if(__builtin_popcount(nums[i]) != __builtin_popcount(bits[i].first))
                return false;
            else{
                for(int j = min(i, bits[i].second); j <= max(i, bits[i].second); j++)
                    if(__builtin_popcount(nums[j]) != __builtin_popcount(bits[i].first))
                        return false;
            }
        return true;
    }
};

int main () {
    
    return 0;
}
