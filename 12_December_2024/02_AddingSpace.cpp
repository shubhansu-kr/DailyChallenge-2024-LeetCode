// https://leetcode.com/problems/adding-spaces-to-a-string/?envType=daily-question&envId=2024-12-03

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
    string addSpaces(string s, vector<int>& spaces) {
        int i = 0; string ans = ""; int j=0;
        for(int i=0;i<s.size(); i++){
            if(j < spaces.size() && i == spaces[j]){
            ans+=" ";
            j++;
            }
            ans+=s[i];
        }
        return ans;
    }
};

int main () {
    
    return 0;
}
