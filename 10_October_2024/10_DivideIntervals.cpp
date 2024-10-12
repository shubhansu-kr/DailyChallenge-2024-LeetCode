// https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/?envType=daily-question&envId=2024-10-12

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
    int minGroups(vector<vector<int>>& intervals) {
        int count = 0;
        int bound_down = 10001;
        int bound_up = -1;
        map<int, int> map_1;
        map<int, int> map_2;
        for (auto it: intervals){
            map_1[it[0]] ++;
            map_2[it[1]] ++;
            bound_down = min(bound_down, it[0]);
            bound_down = min(bound_down, it[1]);
            bound_up = max(bound_up, it[0]);
            bound_up = max(bound_up, it[1]);
        }
        int maxi = -1;
        
        for (int i = bound_down; i <= bound_up; i++){
            if (map_1.find(i) != map_1.end()){
                count += map_1[i];
            }
            if (map_2.find(i) != map_2.end()){
                count -= map_2[i];
            }
            maxi = max(maxi, count);
        }
        if (intervals.size() >= 1 && maxi == 0) return 1;
        return maxi;
    }
};

int main () {
    
    return 0;
}
