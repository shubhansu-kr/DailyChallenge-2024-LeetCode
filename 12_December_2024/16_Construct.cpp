// https://leetcode.com/problems/construct-string-with-repeat-limit/?envType=daily-question&envId=2024-12-17

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
    string repeatLimitedString(string s, int repeatLimit) {
        map<int, int> mp;
        for(int i=0; i<s.length(); i++){
            mp[s[i]]++;
        }
        stack<pair<char, int>> mapped;
        for(auto i : mp){
            mapped.push({i.first, i.second});
        }
        string ans = "";
        while(mapped.size()){
            auto it = mapped.top();
            mapped.pop();

            int n = min(it.second, repeatLimit);
            string temp(n, it.first);
            ans += temp;
            it.second -= n;
            if(it.second){
                if(mapped.empty()){
                    break;
                }
                auto next = mapped.top();
                mapped.pop();
                string nextStr(1, next.first);
                next.second--;
                ans += nextStr;

                if(next.second){
                    mapped.push(next);
                }
                mapped.push(it);
            }
        }
        return ans;
    }
};

int main () {
    
    return 0;
}
