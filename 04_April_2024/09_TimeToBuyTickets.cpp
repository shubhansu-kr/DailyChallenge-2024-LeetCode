// https://leetcode.com/problems/time-needed-to-buy-tickets/?envType=daily-question&envId=2024-04-09

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();

        // Bring to the last.
        for(int i = 0; i <= k; ++i) tickets[i]--;
        int time = k+1;
        int count = tickets[k];
        int i = (k+1) % n;
        while(i != k){
            time += min(count, tickets[i]);
            i = (i+1) % n;
        }
        time += count; 
        return time;
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