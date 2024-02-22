// https://leetcode.com/problems/find-the-town-judge/?envType=daily-question&envId=2024-02-22

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustedBy(n), trusts(n);

        for(auto &it: trust) {
            trustedBy[it[1]-1]++;
            trusts[it[0]-1]++;
        }

        for(int i = 0; i < n; ++i) {
            if (trustedBy[i] == n-1 && trusts[i] == 0) return i+1;
        }

        return -1;
    }
};

int main () {
    
    return 0;
}