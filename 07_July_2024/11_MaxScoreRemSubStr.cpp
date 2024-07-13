// https://leetcode.com/problems/maximum-score-from-removing-substrings/?envType=daily-question&envId=2024-07-12

#include <bits/stdc++.h>
using namespace std ;

class Solution {
    // Approach 2
public:
    int maximumGain(string s, int x, int y) {
        int score = 0, flag = 0;
        if (x < y) {
            flag = 1;
            reverse(s.begin(), s.end());
        }

        int bCount = 0, aCount = 0, abCount = 0;
        for(auto &it: s){
            if (it == 'a') {
                ++aCount;
            }
            else if (it == 'b') {
                if (aCount) {
                    --aCount;
                    ++abCount;
                }
                else {
                    ++bCount;
                }
            }
            else {
                if (flag) {
                    // x is less than y. Multiply with y first
                    score += ((abCount * y) + (x * min(aCount, bCount)));
                }
                else {
                    score += ((abCount * x) + (y * min(aCount, bCount)));
                }

                abCount = 0, bCount = 0, aCount = 0;
            }
        }

        if (flag) {
            score += ((abCount * y) + (x * min(aCount, bCount)));
        }
        else {
            score += ((abCount * x) + (y * min(aCount, bCount)));
        }

        return score;
    }
};

class Solution {
public:
    int solve(string &s, string p, int val, int &ans) {
        vector<char>st;
        for(int i = 0; i < s.length(); i++) {
            if(!st.empty() && st.back() == p[0] && s[i] == p[1]) {
                st.pop_back();
                ans+=val;
            } else st.push_back(s[i]);
        }
        s = "";
        int i = 0;
        while(i < st.size()) {
            s += st[i];
            i++;
        }
        return ans;
    }
    int maximumGain(string s, int x, int y) {
        string p = "", q = "";
        int val, val2;
        int ans = 0;
        if(x > y) {
            p = "ab";
            q="ba";
            val = x;
            val2=y;
        } else {
            p = "ba"; 
            val = y;
            q="ab";
            val2=x;
        }
        solve(s,p,val,ans);
        solve(s,q,val2,ans);
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