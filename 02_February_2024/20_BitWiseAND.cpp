// https://leetcode.com/problems/bitwise-and-of-numbers-range/?envType=daily-question&envId=2024-02-21

#include <bits/stdc++.h>
using namespace std ;


class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
       int s=0;
       while(left<right){
           left>>=1;  
           right>>=1;  
           s++;
       }
       return left<<s;
    }
};

int main () {
    
    return 0;
}