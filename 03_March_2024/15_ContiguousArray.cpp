// https://leetcode.com/problems/contiguous-array/?envType=daily-question&envId=2024-03-16

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum=0, maxLen=0;
        unordered_map<int, int> seen{{0, -1}};
        
        for(int i=0; i<nums.size(); i++){
            sum += nums[i]==1 ? 1 : -1;
            if(seen.count(sum)) maxLen = max(maxLen, i-seen[sum]);
            else seen[sum] = i;
        }
        return maxLen;
    }
};

int main () {
    
    return 0;
}