// https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/?envType=daily-question&envId=2024-09-15

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
    int findTheLongestSubstring(string s) {
        map<int,int>mp;
        mp[0] = -1;
        int cnt = 0,ans =0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
                cnt = cnt^( 1 << ((int)(s[i]-'a')));
            
            if(mp.count(cnt)){
                ans = max(ans,i-mp[cnt]);
            }else{
                mp[cnt] = i;
            }
        }
        return ans;
    }
};

int main () {
    
    return 0;
}
