// https://leetcode.com/problems/circular-sentence/?envType=daily-question&envId=2024-11-02

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
    bool check1(string sentence) {
        int n = sentence.size();
        bool flag = true;
        
        for(int i = 0; i < n; i++) {
            if(sentence[i] == ' ' && sentence[i-1] != sentence[i+1]) {
                flag = false;
            }
        }

        return flag;

    }

    bool check2 (string sentence) {
        int n = sentence.size();
        char start = sentence[0];
        char end = sentence[n-1];

        if(start == end) {
            return true;
        }
        else {
            return false;
        }
    }

    bool isCircularSentence(string sentence) {
        if(check1(sentence) && check2(sentence)) {
            return true;
        }

        return false;
    }
};

int main () {
    
    return 0;
}
