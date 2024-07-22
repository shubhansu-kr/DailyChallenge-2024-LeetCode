// https://leetcode.com/problems/sort-the-people/?envType=daily-question&envId=2024-07-22

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    class compare {
    public:
        bool operator()(pair<string, int>& a, pair<string, int>& b) {
            return a.second < b.second;
        }
    };
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        priority_queue<pair<string, int>, vector<pair<string, int>>, compare>
            pq;
        int n = names.size();
        for (int i = 0; i < n; i++) {
            pq.push({names[i], heights[i]});
        }
        int i = 0;
        while (!pq.empty()) {
            names[i] = pq.top().first;
            pq.pop();
            i++;
        }
        return names;
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