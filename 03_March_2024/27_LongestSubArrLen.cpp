// https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/?envType=daily-question&envId=2024-03-28

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int l = 0, r = 0, n = nums.size();
        int maxLen = 0;
        while(r < n) {
            freq[nums[r]]++;

            while(freq[nums[r]] > k) {
                freq[nums[l++]]--;
            }

            maxLen = max(maxLen, (1 + r - l));

            r++;
        }
        return maxLen;
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