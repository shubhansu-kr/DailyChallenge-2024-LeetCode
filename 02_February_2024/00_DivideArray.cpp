// https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/?envType=daily-question&envId=2024-02-01

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 2; i < nums.size(); i += 3){
            if(nums[i] - nums[i - 2] > k) return {};
            ans.push_back({nums[i-2], nums[i-1], nums[i]});
        }
        return ans;
    }
};

int main () {
    
    return 0;
}