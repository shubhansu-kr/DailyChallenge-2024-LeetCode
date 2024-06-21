// https://leetcode.com/problems/grumpy-bookstore-owner/?envType=daily-question&envId=2024-06-21

#include <bits/stdc++.h>
using namespace std ;


class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        auto satisfied = 0, m_add_satisfied = 0, add_satisfied = 0;
        for (auto i = 0; i < customers.size(); ++i) {
            satisfied += !grumpy[i] * customers[i];
            add_satisfied += grumpy[i] * customers[i];
            if (i >= minutes) 
                add_satisfied -= grumpy[i - minutes] * customers[i - minutes];
            m_add_satisfied = max(m_add_satisfied, add_satisfied);
        }
        return satisfied + m_add_satisfied;
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