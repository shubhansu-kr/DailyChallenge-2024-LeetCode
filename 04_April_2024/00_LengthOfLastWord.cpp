// https://leetcode.com/problems/length-of-last-word/?envType=daily-question&envId=2024-04-01

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<string> splitString(string s, char key) {
        vector<string> res;
        string temp = "";
        for(auto &it: s){
            if(it == key) {
                if (temp != "") res.emplace_back(temp);
                temp = "";
            }
            else {
                temp += it;
            }
        }
        if (temp != "") res.emplace_back(temp);
        return res;
    }
    int lengthOfLastWord(string s) {
        string ans = "", temp = "";
        for(auto &it: s) {
            if (it == ' '){
                if (temp != "") ans = temp;
                temp = "";
            }
            else {
                temp += it;
            }
        }
        if (temp != "") ans = temp;
        return ans.length();
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