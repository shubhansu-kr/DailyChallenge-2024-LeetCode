// https://leetcode.com/problems/water-bottles/?envType=daily-question&envId=2024-07-07

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=numBottles;
        while(numBottles>=numExchange){
            numBottles-=numExchange-1;
            ans++;
        }
        return ans;
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