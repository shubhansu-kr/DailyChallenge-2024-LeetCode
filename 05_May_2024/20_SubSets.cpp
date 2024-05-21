// https://leetcode.com/problems/subsets/?envType=daily-question&envId=2024-05-21

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        sub(nums, temp, ans);
        return ans;
    }
    void sub(vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans, int i = 0)
    {
        if (i >= nums.size())
        {
            ans.emplace_back(temp);
            return;
        }
        temp.emplace_back(nums[i]);
        sub(nums, temp, ans, i + 1);
        temp.pop_back();
        sub(nums, temp, ans, i + 1);
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

int main () {
    
    return 0;
}