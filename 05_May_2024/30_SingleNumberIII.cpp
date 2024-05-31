// https://leetcode.com/problems/single-number-iii/?envType=daily-question&envId=2024-05-31

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<int> singleNumber(vector<int> &nums) {
        unordered_map<int, int> freq;
        // generate freq
        for (auto &num: nums) ++freq[num];
        vector<int> ans;
        // generate ans
        for (auto &[x, f]: freq)
            if (f == 1) {
                ans.push_back(x);
                if (ans.size() == 2)
                    return ans;
            }
        return ans;
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