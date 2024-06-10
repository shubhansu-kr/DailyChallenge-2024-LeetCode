// https://leetcode.com/problems/height-checker/?envType=daily-question&envId=2024-06-10

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected = heights;
        sort(heights.begin(), heights.end());
        int count = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            if (heights[i] != expected[i])
            {
                count++;
            }
        }
        return count;
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