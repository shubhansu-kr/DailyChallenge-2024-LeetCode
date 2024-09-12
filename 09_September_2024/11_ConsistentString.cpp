// https://leetcode.com/problems/count-the-number-of-consistent-strings/?envType=daily-question&envId=2024-09-12

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count = 0;
        set<char> allow;
        for (int i = 0; i < allowed.length(); i++)
        {
            allow.insert(allowed[i]);
        }
        for (int i = 0; i < words.size(); i++)
        {
            int flag = 1;
            for (int j = 0; j < words[i].length(); j++)
            {
                if (!allow.count(words[i][j]))
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1)
            {
                count++;
            }
        }
        return count;
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