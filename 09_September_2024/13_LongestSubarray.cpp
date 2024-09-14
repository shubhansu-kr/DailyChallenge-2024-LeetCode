// https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/?envType=daily-question&envId=2024-09-14

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
    int longestSubarray(vector<int>& nums) {
        int prev=0,ans=INT_MIN,freq=1,curr=nums[0],n=nums.size();
        for(int i=1;i<n;i++){   
            if(nums[i]==nums[i-1]) freq++;
            else{
                if(prev<curr || (prev==curr && freq>ans)) ans=freq,prev=curr;
                freq=1;
                curr=nums[i];
            }
        }
        if(prev<curr) ans=freq,prev=curr;
        return ans;
    }
};

int main () {
    
    return 0;
}
