// https://leetcode.com/problems/ipo/?envType=daily-question&envId=2024-06-15

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects(n);
        for (int i = 0; i < n; i++) {
            projects[i] = {capital[i], profits[i]};
        }
        sort(projects.begin(), projects.end());
        int i = 0;
        priority_queue<int> maximizeCapital;
        while (k--) {
           
            while (i < n && projects[i].first <= w) {
                maximizeCapital.push(projects[i].second);
                i++;
            }
            if (maximizeCapital.empty())
                break;
            w += maximizeCapital.top();
            maximizeCapital.pop();
        }
        return w;
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