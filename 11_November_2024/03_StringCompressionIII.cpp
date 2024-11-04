// https://leetcode.com/problems/string-compression-iii/?envType=daily-question&envId=2024-11-04

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
    string compressedString(string word) {
        string ans = "";
        int count = 1;
        char ch = word[0];

        for(int i=1; i<word.size(); i++){
            if(ch == word[i] && count < 9)
                count++;
            else{
                ans += to_string(count);
                ans += ch;
                ch = word[i];
                count = 1;
            }
        }
        ans += to_string(count);
        ans += ch;
        return ans;
    }
};

int main () {
    
    return 0;
}
