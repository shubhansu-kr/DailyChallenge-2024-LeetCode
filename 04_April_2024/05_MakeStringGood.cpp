// https://leetcode.com/problems/make-the-string-great/?envType=daily-question&envId=2024-04-05

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(auto &it: s) {
            if(st.size()) {
                char top = st.top();
                if (it - top == 32 || top - it == 32) {
                    st.pop();
                }
                else {
                    st.push(it);
                }
            }
            else {
                st.push(it);
            }
        }
        string ans = "";
        while(st.size()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
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