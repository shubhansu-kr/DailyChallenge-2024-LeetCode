// https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/?envType=daily-question&envId=2024-11-07

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
    int largestCombination(vector<int>& candidates) {
        int ans = 0;
        vector<int> cnt(32,0);
        for(auto n : candidates){
            int pos = 0;
            while(n){
                if(n&1) {
                    cnt[pos] += 1;
                    if(ans<cnt[pos]) ans = cnt[pos];
                }
                n = n>>1;
                pos++;
            }
        }
        
        return ans;
    }
};

int main () {
    
    return 0;
}
