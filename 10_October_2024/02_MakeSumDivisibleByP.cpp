// https://leetcode.com/problems/make-sum-divisible-by-p/?envType=daily-question&envId=2024-10-03

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
    int minSubarray(vector<int>& nums, int p) {
        long totalSum=0;
        for(int nums: nums){
            totalSum+=nums;
        }

        totalSum=totalSum%p;
        if(totalSum==0) return 0;

        unordered_map<int,int> prefixMod;
        prefixMod[0]=-1;
        long prefixSum=0;
        int minLength=nums.size();

        for(int i=0;i<nums.size();++i){
            prefixSum+=nums[i];
            int currentMod=prefixSum%p;
            int targetMod=(currentMod-totalSum+p)%p;

            if(prefixMod.find(targetMod)!=prefixMod.end()){
                minLength=min(minLength,i-prefixMod[targetMod]);
            }

            prefixMod[currentMod]=i;
        } 
        return minLength == nums.size()?-1:minLength;
    }
};

int main () {
    
    return 0;
}
