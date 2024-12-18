// https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/?envType=daily-question&envId=2024-12-18

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
    vector<int> finalPrices(vector<int>& prices) {
        for (int i = 0; i < prices.size() - 1; ++i)
        {
            for (int j = i + 1; j < prices.size(); ++j)
            {
                if (prices[i] >= prices[j])
                {
                    prices[i] -= prices[j];
                    break;
                }
            }
        }
        return prices;
    }
};

int main () {
    
    return 0;
}
