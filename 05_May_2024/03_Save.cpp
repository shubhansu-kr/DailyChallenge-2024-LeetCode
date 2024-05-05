// https://leetcode.com/problems/boats-to-save-people/?envType=daily-question&envId=2024-05-04

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int numRescueBoats(vector<int> people, int limit)
    {
        int i, j;
        sort(people.rbegin(), people.rend());
        for (i = 0, j = people.size() - 1; i <= j; ++i)
            if (people[i] + people[j] <= limit)
                j--;
        return i;
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