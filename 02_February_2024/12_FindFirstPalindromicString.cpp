// https://leetcode.com/problems/find-first-palindromic-string-in-the-array/?envType=daily-question&envId=2024-02-13

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    string firstPalindrome(vector<string> &words)
    {
        for (auto &w : words)
            if (equal(begin(w), end(w), rbegin(w)))
                return w;
        return {};
    }
};

int main () {
    
    return 0;
}