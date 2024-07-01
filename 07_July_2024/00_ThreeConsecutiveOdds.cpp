// https://leetcode.com/problems/three-consecutive-odds/?envType=daily-question&envId=2024-07-01

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int odds = 0;
        for (auto i = 0; i < arr.size() && odds < 3; ++i)
            odds = arr[i] % 2 ? odds + 1 : 0;
        return odds == 3;
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