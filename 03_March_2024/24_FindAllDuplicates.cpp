// https://leetcode.com/problems/find-all-duplicates-in-an-array/?envType=daily-question&envId=2024-03-25

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(auto &it: nums){
            int x = abs(it);

            if (nums[x-1] < 0) ans.push_back(x);
            else nums[x-1] = -nums[x-1];
        }
        return ans;
    }
};

int main () {
    
    return 0;
}