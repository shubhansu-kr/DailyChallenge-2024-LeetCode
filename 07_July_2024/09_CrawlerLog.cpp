// https://leetcode.com/problems/crawler-log-folder/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int pos = 0;
        for(auto &it: logs) {
            if (it[0] == '.' ) {
                if (it.length() > 2  && pos != 0) {
                    pos--;
                }
            }
            else {
                ++pos;
            }
        }
        return pos;
    }
};

class Solution {
    // WA : Solution based on assumption that the folder name is a combination of letter and digit.
    // ["1/"] | Expected Result : 1 | Output : 0
public:
    int minOperations(vector<string>& logs) {
        int pos = 0;
        for(auto &it: logs) {
            if (it.length() > 2) {
                if (it[0] == '.') --pos;
                else ++pos;
                pos = max(0, pos);
            }
        }
        return pos;
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