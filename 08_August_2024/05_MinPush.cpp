// https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/?envType=daily-question&envId=2024-08-06

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26);
        for(auto &it: word) {
            freq[it-'a']++;
        }
        sort(freq.begin(), freq.end(), greater<int>());
        int push = 1;
        int ans = 0;
        for(int i = 0; i < 26; ++i) {
            if (i > 0 && i % 8 == 0){
                ++push;
            }
            if (freq[i] == 0) break;
            ans += (push * freq[i]);
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