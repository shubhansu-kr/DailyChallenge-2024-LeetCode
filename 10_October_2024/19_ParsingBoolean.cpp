// https://leetcode.com/problems/parsing-a-boolean-expression/?envType=daily-question&envId=2024-10-20

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
    bool parseBoolExpr(string expression) {
        stack<char> st;

        for (char c : expression) {
            if (c == ')') {
                vector<char> subExpr;
                while (st.top() != '(') {
                    subExpr.push_back(st.top());
                    st.pop();
                }
                st.pop(); 

                char op = st.top();
                st.pop(); 

                if (op == '!') {
                    st.push(subExpr[0] == 't' ? 'f' : 't');
                } else if (op == '&') {
                    char result = 't';
                    for (char e : subExpr) {
                        if (e == 'f') {
                            result = 'f';
                            break;
                        }
                    }
                    st.push(result);
                } else if (op == '|') {
                    char result = 'f';
                    for (char e : subExpr) {
                        if (e == 't') {
                            result = 't';
                            break;
                        }
                    }
                    st.push(result);
                }
            } else if (c != ',') {
                st.push(c);
            }
        }
        
        return st.top() == 't';
    }
};

int main () {
    
    return 0;
}
