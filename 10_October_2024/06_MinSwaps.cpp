// https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/?envType=daily-question&envId=2024-10-08

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
    int minSwaps(string str) {
        set<int, greater<int>>s;
        for(int i=0;i<str.size();i++)if(str[i]=='[')s.insert(i);
        stack<char>st;
        int ans=0;
        for(auto c:str){
            if(c=='[')st.push(c);
            else if(st.empty()){
                st.push('[');
                str[*s.begin()]=']';
                s.erase(s.begin());
                ans++;
            }else st.pop();
        }
        return ans;
    }
};

int main () {
    
    return 0;
}
