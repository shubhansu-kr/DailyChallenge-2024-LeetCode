// https://leetcode.com/problems/determine-if-string-halves-are-alike/?envType=daily-question&envId=2024-01-12

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
   bool isVovel(char c)
    {
        return (c == 'a' || c == 'u' || c == 'o' || c == 'i' ||
                c == 'e' || c == 'A' || c == 'O' || c == 'I' || c == 'E' ||
                c == 'U');
    }
    bool halvesAreAlike(string s)
    {
        int n = s.length() / 2;
        int counti = 0, countj = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (isVovel(s[i]))
            {
                if (i < n)
                {
                    counti++;
                }
                else
                {
                    countj++;
                }
            }
        }
        return counti == countj;
    }
};
int main () {
    
    return 0;
}