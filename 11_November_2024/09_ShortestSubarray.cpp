// https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii/?envType=daily-question&envId=2024-11-10

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
    void bit_initializer(vector<int>& arr, int x) {
        int i = 0;
        while (x) {
            if (x & 1) arr[i]++;
            x >>= 1;
            i++;
        }
    }
    void bit_changer(vector<int>& arr, int& or_result, int x, int z) {
        int i = 0;
        int temp_or = or_result;
        while (x) {
            if (x & 1) {
                arr[i]--;
                if (arr[i] == 0) {
                    or_result ^= (1 << i);
                }
            }
            x >>= 1;
            i++;
        }
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int> arr(32, 0);
        int i = 0, j = 0, or_result = 0, ans = INT_MAX;
        while (j < nums.size()) {
            bit_initializer(arr, nums[j]);
            or_result |= nums[j];
            while (or_result >= k && i <= j) {
                ans = min(ans, j - i + 1); 
                bit_changer(arr, or_result, nums[i], k) ;
                i++; 
            }
            j++;
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};


int main () {
    
    return 0;
}
