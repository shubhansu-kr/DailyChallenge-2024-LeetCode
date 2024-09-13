// https://leetcode.com/problems/xor-queries-of-a-subarray/?envType=daily-question&envId=2024-09-13

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
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> res;
        for (int i = 1; i < arr.size(); ++i)
            arr[i] ^= arr[i - 1];
        for (auto &q: queries)
            res.push_back(q[0] > 0 ? arr[q[0] - 1] ^ arr[q[1]] : arr[q[1]]);
        return res;
    }
};

int main () {
    
    return 0;
}