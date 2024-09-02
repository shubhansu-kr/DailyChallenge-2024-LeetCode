// https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/?envType=daily-question&envId=2024-09-02

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long chalkSum = 0; 
        for(auto &it: chalk) chalkSum += it;
        k %= chalkSum;

        for(int i = 0; i < chalk.size(); ++i) {
            if (k < chalk[i]) return i;
            k -= chalk[i];
        }
        return 0;
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