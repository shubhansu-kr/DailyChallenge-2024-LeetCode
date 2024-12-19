// https://leetcode.com/problems/max-chunks-to-make-sorted/?envType=daily-question&envId=2024-12-19

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
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0, max_so_far = -1;
        for(int i = 0; i < arr.size(); i++) {
            max_so_far = max(max_so_far, arr[i]);
            ans += (max_so_far == i);
        }
        return ans;
    }
};

int main () {
    
    return 0;
}
