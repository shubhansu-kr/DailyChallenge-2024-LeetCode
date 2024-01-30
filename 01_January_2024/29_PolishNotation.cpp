// https://leetcode.com/problems/evaluate-reverse-polish-notation/?envType=daily-question&envId=2024-01-30

#include <bits/stdc++.h>
using namespace std ;

class Solution
{
    // Runtime error: Integer overflow
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<long long> st;
        long long a, b;
        for (auto &it : tokens)
        {
            if (it == "/" || it == "*" || it == "+" || it == "-")
            {
                b = st.top();
                st.pop();
                a = st.top();
                st.pop();

                if (it == "*"){st.push(a*b);}
                else if (it == "+"){st.push(a+b);}
                else if (it == "-"){st.push(a-b);}
                else{st.push(a/b);}
            }
            else{st.push(stoi(it));}
        }
        return st.top();
    }
};

int main () {
    
    return 0;
}