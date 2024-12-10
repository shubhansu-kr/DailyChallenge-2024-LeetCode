// https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i/?envType=daily-question&envId=2024-12-10

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
    int maximumLength(string s) {
        cin.tie(NULL);
        ios_base::sync_with_stdio(false);
        int ans=-1;
        unordered_map<char,int> um;
        for(char ele:s) {
            um[ele]++;
        }
        for(auto ele:um) {
            if(ele.second>= 3) {
                ans=1;
                break;
            }
        }
        string sub="";

        for(int i=0;i<s.size();i++) {
            sub="";
            sub+=s[i];
            for(int j=i+1;j<s.size();j++) {
                sub+=s[j];
                if(sub.size()>ans) {
                    if(check(sub)) {
                        // cout<<sub<<" ";
                        if(existThrice(sub,s)) {
                            // cout<<"yes"<<"\n";
                            ans=sub.size();
                        }
                    }
                }
            }
        }

        // cout<<existThrice("aa",s);

        return ans;

    }

    bool existThrice(string sub,string s) {
        int n=s.size()-sub.size();
        int ct=0;
        for(int i=0;i<=n;i++) {
            if(s.substr(i,sub.size()) == sub) {
                if(++ct == 3) return true;
            }
        }
        return false;
    }
    bool check(string s){
        for(int i=1;i<s.size();i++){
            if(s[i-1]!=s[i]) return 0;
        }
        return 1;
    }
};

int main () {
    
    return 0;
}
