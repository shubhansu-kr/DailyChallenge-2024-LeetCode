// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/?envType=daily-question&envId=2024-01-13

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int minSteps(string s, string t) {
       map<char, int> p;
        for (int i = 0; i < s.length(); i++)
        {
            ++p[s[i]];
        }
        int count = 0;
        for (int j = 0; j < s.length(); j++)
        {
            if (p[t[j]] > 0)
            {
                p[t[j]]--;
            }
            else
            {
                count++;
            }
        }
        return count;
    }
};

int main () {
    
    return 0;
}