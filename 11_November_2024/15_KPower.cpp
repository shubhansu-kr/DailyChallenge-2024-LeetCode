// https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/?envType=daily-question&envId=2024-11-16

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
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>cnt(n);
        cnt[0] = 0;
        for(int i = 1; i < n; i++){
            if(nums[i] <= nums[i-1] || nums[i] - nums[i-1] > 1)cnt[i]++;
            cnt[i] += cnt[i-1];
        }
        vector<int>ans;
        for(int i = 0; i < n-k+1; i++){
            if(cnt[i+k-1] - cnt[i]){
                ans.push_back(-1);
                continue;
            }
            ans.push_back(nums[i+k-1]);
        }
        return ans;
    }
};

int main () {
    
    return 0;
}
