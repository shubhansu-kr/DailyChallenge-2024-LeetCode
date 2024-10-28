// https://leetcode.com/problems/longest-square-streak-in-an-array/description/?envType=daily-question&envId=2024-10-28

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
    int longestSquareStreak(vector<int>& nums) {
        int res=0;
        unordered_set<long long> st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int temp=1;
            long long a=nums[i];
            int cnt=1;
            while(cnt<nums.size() && st.find(a*a)!=st.end()){
                cnt++;
                a=a*a;
                temp++;
                // if(cnt==nums.size())
                // return max(temp,res);
            }
            // if()
            res=max(res,temp);
        }
        if(res<2)
        return -1;
        return res;
    }
};

int main () {
    
    return 0;
}
