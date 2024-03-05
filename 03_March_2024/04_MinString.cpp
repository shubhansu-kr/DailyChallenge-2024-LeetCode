// https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/?envType=daily-question&envId=2024-03-05

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int minimumLength(string s) {
        int i = 0, j = s.length()-1;
        while(i < j) {
            if (s[i] != s[j]) break;
            char temp = s[i];
            while(i <= j && s[i] == temp) ++i;
            while(i <= j && s[j] == temp) --j;
        }

        return max(0, j-i+1);
    }
};
int main () {
    
    return 0;
}