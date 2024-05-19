// https://leetcode.com/problems/find-the-maximum-sum-of-node-values/?envType=daily-question&envId=2024-05-19

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<long long>> temp(n, vector<long long>(2, -1)); // temp[current_index(node)][is_even]
        
        return calculateMax(nums, n, k, 0, 1, temp);
    }

private:
    long long calculateMax(vector<int>& nums, int n, int k, int curInd, int isEven, vector<vector<long long>>& temp) {
        if (curInd == n) {  
            return isEven == 1 ? 0 : LLONG_MIN;
        }
        if (temp[curInd][isEven] != -1) {  
            return temp[curInd][isEven];
        }

        long long noXor = nums[curInd] + calculateMax(nums, n, k, curInd + 1, isEven, temp); 
        long long withXor = (nums[curInd] ^ k) + calculateMax(nums, n, k, curInd + 1, !isEven, temp);

        long long mxPossible = max(noXor, withXor);
        temp[curInd][isEven] = mxPossible;
        return mxPossible;
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