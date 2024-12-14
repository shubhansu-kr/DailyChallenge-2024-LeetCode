// https://leetcode.com/problems/continuous-subarrays/?envType=daily-question&envId=2024-12-14

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
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long count = 0;
        int left = 0;

        multiset<int> window;

        for (int right = 0; right < n; ++right) {
            window.insert(nums[right]);

            while (*window.rbegin() - *window.begin() > 2) {
                window.erase(window.find(nums[left]));
                ++left;
            }

            count += (right - left + 1);
        }

        return count;
    }
};

int main () {
    
    return 0;
}
