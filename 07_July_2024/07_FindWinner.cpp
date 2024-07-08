// https://leetcode.com/problems/find-the-winner-of-the-circular-game/?envType=daily-question&envId=2024-07-08

#include <bits/stdc++.h>
using namespace std ;

class Solution {
    // BruteForce : Simulate using queue 
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i = 1; i <= n; ++i) {
            q.push(i);
        }

        while(q.size() > 1) {
            int temp = k-1;
            while(temp--) {
                q.push(q.front());
                q.pop();
            }

            q.pop();
        }

        return q.front();
    }
};

class Solution {
    // BruteForce : Simulate
    // Not getting anywhere 
public:
    int findTheWinner(int n, int k) {
        vector<int> winner(n, 1);
        int p = 0, q = n;
        while(q != 1) {
            p = (p + k) % n;
            winner[p-1] = 0;
            q--;
        }

        for(int i = 0; i < winner.size(); ++i) {
            if (winner[i]) return i+1;
        }

        return q;
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