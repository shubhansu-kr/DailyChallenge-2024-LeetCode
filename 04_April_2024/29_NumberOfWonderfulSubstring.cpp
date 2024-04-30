// https://leetcode.com/problems/number-of-wonderful-substrings/?envType=daily-question&envId=2024-04-30

#include <bits/stdc++.h>
using namespace std ;

#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    long long wonderfulSubstrings(string& word) {
        uint16_t freq[1024] = {0}; 
        bitset<10> charSet=0;
        vector<uint16_t> prefix={0};
        vector<char> chars;
        uint16_t sum = 0;
        freq[0] = 1; 
        for (int c : word) {
            int index = c - 'a';
            if (charSet[index]==0) chars.push_back(index);
            charSet[index]=1;
            sum ^= (1 << index);
            freq[sum]++;
            if (freq[sum]==1) prefix.push_back(sum);
        }

        long long cnt = 0, cnt1 = 0;
        for (auto i: prefix) { 
            long long f=freq[i];
            if (f == 0)
                continue;
            cnt += f*(f-1) / 2; 
            for (char b: chars) {
                int j=i^(1<< b);
                cnt1+=f*freq[j]; 
            }
        }
        return cnt + cnt1 / 2;
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