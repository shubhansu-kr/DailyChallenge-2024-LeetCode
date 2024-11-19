// https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/?envType=daily-question&envId=2024-11-19

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
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        bool prevFlag = true, flag = true;
        long long ans = 0, subSum = 0;

        unordered_map<int, int> mp;

        for (int i = 0; i < k; ++i)
        {
            if (mp[nums[i]]++) flag = false;
            subSum += nums[i];
        }
        
        if (flag) ans = max(ans, subSum);

        prevFlag = flag;
        flag = true;

        for (int i = k; i < n; ++i)
        {
            subSum += (nums[i] - nums[i-k]);

            // Check Distinct Element
            mp[nums[i-k]]--;
            if (mp[nums[i]]++) flag = false;
            if (!prevFlag && flag) {
                for(auto &it: mp) {
                    if (it.second > 1) 
                    {
                        flag = false;
                        break;
                    }
                }
            }

            if (flag) ans = max(ans, subSum);

            prevFlag = flag;
            flag = true;
        }
        
        return ans;
    }
};

int main () {
    
    return 0;
}
