// https://leetcode.com/problems/rotate-string/?envType=daily-question&envId=2024-11-03

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

vector<int> computeZArray(const string &str) {
    int n = str.size();
    vector<int> z(n, 0);
    int left = 0, right = 0;
    for (int i = 1; i < n; i++) {
        if (i <= right)
            z[i] = min(right - i + 1, z[i - left]);
        while (i + z[i] < n && str[z[i]] == str[i + z[i]])
            z[i]++;
        if (i + z[i] - 1 > right) {
            left = i;
            right = i + z[i] - 1;
        }
    }
    return z;
}

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size())
            return false;

        string concatenated = s + '#' + goal + goal;
        vector<int> zArray = computeZArray(concatenated);

        int originalSize = s.size();
        for (int i = originalSize + 1; i < zArray.size(); ++i) {
            if (zArray[i] == originalSize) {
                return true;
            }
        }
        return false;
    }
};

int main () {
    
    return 0;
}
