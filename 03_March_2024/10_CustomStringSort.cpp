// https://leetcode.com/problems/custom-sort-string/?envType=daily-question&envId=2024-03-11

#include <bits/stdc++.h>
using namespace std ;

class Solution {
  public:
    string customSortString(string order, string s) {
        sort(s.begin(), s.end(),
             [&](char a, char b) { return order.find(a) < order.find(b); });
        return s;
    }
};

class Solution {
    // Compilation Error
public:
    vector<int> p;
    bool myComp(char &a, char &b){
        if (p[a] < p[b]) {
            return true;
        }
        else if (p[a] == p[b]) {
            return a < b;
        }
        return false;
    }
    string customSortString(string order, string s) {
        vector<int> pr(26, 26);
        int i = 0;
        for(auto &it: order){
            pr[it-'a'] = i++;
        }
        p = pr;
        sort(s.begin(), s.end(), myComp);
        return s;
    }
};

int main () {
    
    return 0;
}