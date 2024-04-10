// https://leetcode.com/problems/reveal-cards-in-increasing-order/?envType=daily-question&envId=2024-04-10

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();

        sort(deck.begin(), deck.end());

        vector<int> ans(n);
        int i = 0, k = 0, toggle = 1;
        while(true){
            if (k == n) break;

            if (!ans[i]){
                if (toggle % 2) {
                    ans[i] = deck[k++];
                }
                ++toggle;
            }
            i = (i+1) % n;
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
    for(int i = 0; i < 1000; ++i) {
        cout << i + 1 << ", ";
    }
    return 0;
}