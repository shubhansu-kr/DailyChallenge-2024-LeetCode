// https://leetcode.com/problems/power-of-two/?envType=daily-question&envId=2024-02-19  

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool isPowerOfTwo(int n)
    {
        if (n <= 0)
            return false;
        return check(n);
    }
    bool check(int &n)
    {
        if (n % 2 == 0)
        {
            n /= 2;
            return check(n);
        }
        else
        {
            return n == 1;
        }
        // return false ;
    }
};

int main () {
    
    return 0;
}