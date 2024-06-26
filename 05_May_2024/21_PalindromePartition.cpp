// https://leetcode.com/problems/palindrome-partitioning/?envType=daily-question&envId=2024-05-22

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool isValidPalindrome(string &s) {
        for (int i = 0; i < s.length()/2; ++i)
        {
            if (s[i] != s[s.length()-i-1]) return false;
        }
        return true;        
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> sub;
        solve(ans, sub, s);
        return ans;
    }

    void solve(vector<vector<string>> &ans, vector<string> &sub, string &s, int i = 0){
        if (i >= s.size()){
            ans.emplace_back(sub);
            return;
        }

        for (int len = 1; len <= (s.length() - i); ++len)
        {
            string temp = s.substr(i, len);
            if (isValidPalindrome(temp)){
                sub.emplace_back(temp);
                solve(ans, sub, s, i+len);
                sub.pop_back();
            }
        }         
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