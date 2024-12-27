// https://leetcode.com/problems/best-sightseeing-pair/?envType=daily-question&envId=2024-12-27

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxi=INT_MIN;
        int n=values.size();
        int val=values[0];
        for(int i=1;i<n;i++){
            maxi=max(maxi,val+values[i]-i);
            val=max(val,values[i]+i);
        }
        return maxi;
    }
};

int main () {
    
    return 0;
}
