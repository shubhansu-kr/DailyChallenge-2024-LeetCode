// https://leetcode.com/problems/maximum-width-ramp/?envType=daily-question&envId=2024-10-10

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
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        multimap<int, int> ans;

        for (int i = 0; i < n; ++i) {
            ans.insert({nums[i], i});
        }

        int maxi = 0;
        int min_ind = n;  

        for (auto it : ans) {
            maxi = max(maxi, it.second - min_ind);
            min_ind = min(min_ind, it.second);
        }

        return maxi;
    }
};

int main () {
    
    return 0;
}
