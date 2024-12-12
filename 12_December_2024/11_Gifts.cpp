// https://leetcode.com/problems/take-gifts-from-the-richest-pile/description/?envType=daily-question&envId=2024-12-12

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
    long long pickGifts(vector<int>& gifts, int k) {
        long long sum=accumulate(gifts.begin(), gifts.end(), 0LL);
        priority_queue<int> pq(gifts.begin(), gifts.end());
        for (int i=0, x=INT_MAX, y; i<k && x>1; i++){
            x=pq.top(), y=sqrt(x);
            pq.pop();
            sum-=(x-y);
            pq.push(y);
        }
        return sum;
    }
};

int main () {
    
    return 0;
}
