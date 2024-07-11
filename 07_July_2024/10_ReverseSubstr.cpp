// https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/?envType=daily-question&envId=2024-07-11

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>st;
        string res = "";
        int n = s.length();
        for(int i=0; i<n; i++){
            if(s[i]==')'){
                string temp = "";
            
                while(!st.empty() && st.top() != '('){
                    temp += st.top();
                    st.pop();
                }
                if(!st.empty())
                 st.pop();

                cout<<temp<<" ";
                for(auto x : temp) st.push(x);
            }
            else
             st.push(s[i]);
        }

        while(!st.empty()){
            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());
        return res;
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