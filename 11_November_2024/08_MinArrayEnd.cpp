//  https://leetcode.com/problems/minimum-array-end/?envType=daily-question&envId=2024-11-09

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

#define isBit1(x,i) (((x) >> (i)) & 1) 

class Solution {
public:
    inline long long setBit1(long long x, int i) {
        return (x | (1LL << i));
    }

    inline long long setBit0(long long x, int i) {
        return (x & ~(1LL << i));
    }

    long long minEnd(int n, int x) {
        long long ans = x;
        int i = 0;
        long long temp=n-1;
        for (int j = 0; j < 64; j++) {
            if(pow(2,i)>temp)   break;
            if (isBit1(ans, j) == 0) {
                if (isBit1(temp, i) == 1) 
                    ans = setBit1(ans, j); 
                i++;
            }
        }
        return ans;
    }
};

int main () {
    
    return 0;
}
