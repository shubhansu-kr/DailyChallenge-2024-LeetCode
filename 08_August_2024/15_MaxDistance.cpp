// https://leetcode.com/problems/maximum-distance-in-arrays/?envType=daily-question&envId=2024-08-16

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mini=INT_MAX, mini2 = INT_MAX;
        int maxi=INT_MIN, maxi2 = INT_MIN;
        int minIndex = -1, maxIndex = -1;
        for(int i = 0; i < arrays.size(); ++i) {
            if (arrays[i][0] <= mini) {
                minIndex = i;
                mini2 = mini;
                mini = arrays[i][0];
            }
            else if (arrays[i][0] < mini2) {
                mini2 = arrays[i][0];
            }
            
            int k = arrays[i].size();
            if (arrays[i][k-1] >= maxi) {
                maxIndex = i;
                maxi2 = maxi;
                maxi = arrays[i][k-1];
            }
            else if (arrays[i][k-1] > maxi2) {
                maxi2 = arrays[i][k-1];
            }
        }
        if (minIndex == maxIndex) {
            return max(maxi - mini2, maxi2 - mini);
        }
        else {
            return maxi - mini;
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