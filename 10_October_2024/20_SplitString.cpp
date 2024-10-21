// https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/?envType=daily-question&envId=2024-10-21

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
    void fun(int ind,string s,int count,int &maxi,set<string>&st){
        if(ind == s.size()){
            return;
        }

        string k = "";
        for(int i = ind;i<s.size();i++){
            k+=s[i];
            if(st.find(k)==st.end()){
                count++;
                maxi=max(maxi,count);
                st.insert(k);
                fun(i+1,s,count,maxi,st);
                st.erase(st.find(k));
                count--;
            }
        }
    }
public:
    int maxUniqueSplit(string s) {
        int maxi = 0;
        set<string>st;
        fun(0,s,0,maxi,st);
        return maxi;
    }
};

int main () {
    
    return 0;
}
