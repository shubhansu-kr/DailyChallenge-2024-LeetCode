// https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/?envType=daily-question&envId=2024-01-02

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n + 10);
        vector<vector<int>> res;
        for (int a : nums) {
            if (res.size() <= count[a])
                res.push_back({});
            res[count[a]++].push_back(a);
        }
        return res;
    }
};

int main () {
    
    return 0;
}