// https://leetcode.com/problems/remove-k-digits/?envType=daily-question&envId=2024-04-11

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.length() <= k)   
            return "0";
        
        if(k == 0)
            return num;
        
        string res = "";// result string
        stack <char> s; // char stack
        
        s.push(num[0]); // pushing first character into stack
        
        for(int i = 1; i<num.length(); ++i)
        {
            while(k > 0 && !s.empty() && num[i] < s.top())
            {
                --k;
                s.pop();
            }
            
            s.push(num[i]);
            
            if(s.size() == 1 && num[i] == '0') s.pop();
        }
        
        while(k && !s.empty())
        {
            --k;
            s.pop();
        }
        
        while(!s.empty())
        {
            res.push_back(s.top()); // pushing stack top to string
            s.pop(); // pop the top element
        }
        
        reverse(res.begin(),res.end()); // reverse the string 
        
        if(res.length() == 0)
            return "0";
        
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