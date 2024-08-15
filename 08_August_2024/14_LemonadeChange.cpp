// https://leetcode.com/problems/lemonade-change/?envType=daily-question&envId=2024-08-15

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> coins(4, 0);
        for(auto &it: bills) {
            coins[it/5-1]++;
            
            int change = it - 5;
            if (change == 15) {
                if (coins[1] && coins[0]) {
                    --coins[1], --coins[0];
                }
                else if (coins[0] > 2) {
                    coins[0] -= 3;
                }
                else {
                    return false;
                }
            }
            else if (change == 10) {
                if (coins[1]) --coins[1];
                else if (coins[0] > 1) coins[0] -= 2;
                else return false;
            }
            else if (change == 5) {
                if (coins[0]) --coins[0];
                else return false;
            }
        }
        return true;
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