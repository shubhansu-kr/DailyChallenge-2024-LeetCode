// https://leetcode.com/problems/number-of-wonderful-substrings/?envType=daily-question&envId=2024-04-30

#include <bits/stdc++.h>
using namespace std ;

class Solution {
    public long wonderfulSubstrings(String word) {
        long[] cnt = new long[1024]; 
        cnt[0] = 1; 
        int mask = 0; 
        long ans = 0;
        char[] chars = word.toCharArray();
        for (char c : chars) {
            int idx = c - 'a';
            mask ^= 1 << idx; 
            ans += cnt[mask]; 
            for (int i = 1; i <= 512; i*=2) {
                ans += cnt[mask ^ i];
            }
            cnt[mask]++; 
        }
        return ans;
    }
}

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

int main () {
    
    return 0;
}