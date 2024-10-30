// https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/?envType=daily-question&envId=2024-10-30

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

const int inf = 1e9;
class Solution {
public:
    vector<int> get_lis(vector<int> &nums){
        vector<int> lis, ans(nums.size());
        for(int i = 0; i < nums.size(); ++i){
            int id = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
            ans[i] = id;
            if(id == lis.size()) lis.push_back(nums[i]);
            lis[id] = nums[i];
        }
        return ans;
    }
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int> L = get_lis(nums);
        reverse(nums.begin(),nums.end());
        vector<int> R = get_lis(nums);
        int ans =0 ;
        for(int i = 0; i < n;++i){
            if(!L[i] || !R[n-i-1]) continue;
            ans = max(ans, L[i] + R[n-i-1] + 1);
        }
        return n-ans;
    }
};

int main () {
    
    return 0;
}
