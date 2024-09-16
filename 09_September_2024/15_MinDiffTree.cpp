// https://leetcode.com/problems/minimum-time-difference/?envType=daily-question&envId=2024-09-16

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
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        for (const auto& time : timePoints) {
            int hour =  stoi(time.substr(0, 2));
            int minute =  stoi(time.substr(3, 2));
            minutes.push_back(hour * 60 + minute);
        }
        
        sort(minutes.begin(), minutes.end());
        int minDiff = INT_MAX;
        
        for (size_t i = 1; i < minutes.size(); ++i) {
            minDiff =  min(minDiff, minutes[i] - minutes[i - 1]);
        }
        
        minDiff =  min(minDiff, 1440 - (minutes.back() - minutes.front()));
        
        return minDiff;
    }
};

int main () {
    
    return 0;
}
