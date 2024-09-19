// https://leetcode.com/problems/different-ways-to-add-parentheses/?envType=daily-question&envId=2024-09-19

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
    unordered_map<string, vector<int>> dp;
    
    int calculate(int a, int b, char op) {
        switch(op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            default: return 0;
        }
    }

    vector<int> diffWaysToCompute(string expression) {
        if (dp.find(expression) != dp.end()) 
            return dp[expression];
        
        vector<int> ans;
        
        if (expression.find_first_of("+-*") == string::npos) {
            return {stoi(expression)};
        }

        for (int i = 0; i < expression.size(); ++i) {
            if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));

                for (int l : left) {
                    for (int r : right) {
                        ans.push_back(calculate(l, r, expression[i]));
                    }
                }
            }
        }

        return dp[expression] = ans;
    }
};

int main () {
    
    return 0;
}
