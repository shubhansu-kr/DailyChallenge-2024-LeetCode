// https://leetcode.com/problems/ugly-number-ii/?envType=daily-question&envId=2024-08-18

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int nthUglyNumber(int n) {

        if (n == 0 || n == 1)
            return n;

        priority_queue<long, vector<long>, greater<long>> minheap;

        vector<int> primes = {2, 3, 5};
        unordered_set<long> seen;

        minheap.push(1);
        seen.insert(1);
        long ugly = 1;

        for (int i = 0; i < n; i++) {
            ugly = minheap.top();
            minheap.pop();

            for (int prime : primes) {
                long nextugly = ugly * prime;
                if (seen.find(nextugly) == seen.end()) {
                    minheap.push(nextugly);
                    seen.insert(nextugly);
                }
            }
        }
        return (int)ugly;
    }
};

class Solution {
    // WA : Does not increment in succession: Use Min Heap instead
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(1, 1);
        unordered_set<int> dis;
        
        int index = 0; 
        while(ugly.size() < n) {
            int sub = ugly[index];
            int tw = sub * 2, th = sub * 3, f = sub * 5;
            if (!dis.count(tw)) {
                ugly.emplace_back(tw);
                dis.insert(tw);
                if (ugly.size() == n) break;
            }
            if (!dis.count(th)) {
                ugly.emplace_back(th);
                dis.insert(th);
                if (ugly.size() == n) break;
            }
            if (!dis.count(f)) {
                ugly.emplace_back(f);
                dis.insert(f);
                if (ugly.size() == n) break;
            }
            ++index;
        }

        int ans = INT_MIN;
        for(auto &it: ugly) {
            cout << it << " ";
            if (it > ans) ans = it;
        }
        return ans;
    }
};

class Solution {
    // bruteForce : TLE 
public:
    void solve(int k, vector<bool> &dp) {
        if (k >= dp.size() || dp[k]) return;

        dp[k] = true;
        solve(k*2, dp);
        solve(k*3, dp);
        solve(k*5, dp);
    }

    int nthUglyNumber(int n) {
        int sz = INT_MAX;
        vector<bool> dp(sz, false);

        queue<int> q;
        q.push(2);
        q.push(3);
        q.push(5);

        while(q.size()){
            int tp = q.front();
            q.pop();
            if (tp >= sz) break;
            if (dp[tp]) continue;

            dp[tp] = true;
            int twice = tp * 2, thrice = tp * 3, fifth = tp *5;
            q.push(twice);
            q.push(thrice);
            q.push(fifth);
        }

        vector<int> uglyNumbers;
        for(int i = 0; i < sz; ++i) {
            if (dp[i]) uglyNumbers.emplace_back(i);
        }
        return uglyNumbers.size();
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

int main () {
    Solution1 obj;
    cout << obj.nthUglyNumber(10);
    return 0;
}