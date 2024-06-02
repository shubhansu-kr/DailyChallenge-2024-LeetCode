// https://leetcode.com/problems/reverse-string/?envType=daily-question&envId=2024-06-02

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    
        void reverseString(vector<char> &s)
    {
        stack<char> p;
        for (auto a : s)
        {
            p.push(a);
        }
        for (int i = 0; i < s.size(); i++)
        {
            s[i] = p.top();
            p.pop();
        }
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