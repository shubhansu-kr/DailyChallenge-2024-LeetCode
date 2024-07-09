// https://leetcode.com/problems/average-waiting-time/?envType=daily-question&envId=2024-07-09

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double n = customers.size();

        double avgWaitTime = 0;
        int currentTime = customers[0][0];
        for(int i = 0; i < n; ++i) {
            if (currentTime > customers[i][0]) {
                currentTime += customers[i][1];
            }
            else {
                currentTime = customers[i][0] + customers[i][1];
            }
            double waitTime = (double)(currentTime - customers[i][0]);
            avgWaitTime += (double)(waitTime/n);
        }
        return avgWaitTime;
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