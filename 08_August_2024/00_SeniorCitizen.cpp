// https://leetcode.com/problems/number-of-senior-citizens/?envType=daily-question&envId=2024-08-01

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        char ones, tens;
        int age;
        for(auto &it: details){
            tens = it[11];
            ones = it[12];

            int age = (tens-'0') * 10 + (ones-'0');
            if (age > 60) ++count;
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