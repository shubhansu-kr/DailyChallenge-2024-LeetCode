// https://leetcode.com/problems/first-unique-character-in-a-string/description/?envType=daily-question&envId=2024-02-05

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, pair<int, int>> p;
        for (int i = 0; i < s.length(); ++i)
        {
            p[s[i]].first++;
            p[s[i]].second = i ;
        }
        int ans = INT_MAX;
        for(auto &a: p)
        {
            if (a.second.first == 1) ans = min (ans, a.second.second);
        }
        return ans == INT_MAX?-1: ans;
    }
};

int main () {
    
    return 0;
}