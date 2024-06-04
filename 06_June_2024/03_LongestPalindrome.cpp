// https://leetcode.com/problems/longest-palindrome/?envType=daily-question&envId=2024-06-04

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    static int longestPalindrome(string& s) {
        bitset<58> freq=0; //'A'=65~'z'=122
        for(char c: s)
            freq.flip(c-'A');
        int odd=freq.count();
        return s.size()-odd+(odd>=1);
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