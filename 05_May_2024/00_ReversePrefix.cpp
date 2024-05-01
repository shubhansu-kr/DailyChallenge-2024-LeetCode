// https://leetcode.com/problems/reverse-prefix-of-word/?envType=daily-question&envId=2024-05-01

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int range = 0;
        for (int i = 0; i < word.length(); i++)
        {
            if (word[i] == ch)
            {
                range = i+1;
                break;
            }
        }
        if (range)
        {
            reverse(word.begin(), word.begin() + range);
        }
        return word;
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