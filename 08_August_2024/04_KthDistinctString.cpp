// https://leetcode.com/problems/kth-distinct-string-in-an-array/?envType=daily-question&envId=2024-08-05

#include <bits/stdc++.h>
using namespace std ;

class Solution {
    // BruteForce: Use maps to check.
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;
        for(auto &it: arr) {
            mp[it]++;
        }
        for(auto &it: arr) {
            if (mp[it] == 1) --k;
            if (k == 0) return it;
        }
        return "";
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