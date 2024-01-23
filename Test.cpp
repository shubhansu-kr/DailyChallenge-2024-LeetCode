// Test - DP

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int solve(vector<int>& nums,int n,int ind,int jumps){
        if(ind>=n)return INT_MAX;
        if(ind==n-1){
            return jumps;
        }
        int ans = INT_MAX;
        for(int i=1;i<=nums[ind];i++){
            ans = min(ans,solve(nums,n,ind+i,jumps+1));
        }
        return ans;
    }
    int jump(vector<int>& nums) {
        int ans = solve(nums,nums.size(),0,0);
        return ans;
    }
};

class Solution1 {
public:
    int solve(vector<int>& nums,vector<int>&dp,int n,int ind,int jumps){
        if(ind>=n)return INT_MAX;
        if(ind==n-1){
            return dp[ind] = jumps;
        }

        if(dp[ind]!=-1)return dp[ind];

        int ans = INT_MAX;

        for(int i=1;i<=nums[ind];i++){
            ans = min(ans,solve(nums,dp,n,ind+i,jumps+1));
        }

        return dp[ind]=ans;
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        int ans = solve(nums,dp,nums.size(),0,0);
        for(int i=0;i<dp.size();i++){
            cout<<dp[i]<<" ";
        }
        return dp[n-1];
    }
};

// [5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5]

int main () {
    
    vector<int> nums = {5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5};

    Solution1 obj;
    cout << obj.jump(nums);
    return 0;
}