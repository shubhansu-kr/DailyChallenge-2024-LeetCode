// https://leetcode.com/problems/set-mismatch/?envType=daily-question&envId=2024-01-22

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> krs(nums.size());
        for(auto &it: nums){
            krs[it-1]++;
        }
        vector<int> ans(2, 0);
        for (int i = 0; i < krs.size(); ++i)
        {
            if (krs[i] == 0){
                ans[1] = i+1;
            }
            else if (krs[i] == 2){
                ans[0] = i+1 ;
            }
        }
        return ans;
    }
};

int main () {
    
    return 0;
}