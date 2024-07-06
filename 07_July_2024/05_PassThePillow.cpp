// https://leetcode.com/problems/pass-the-pillow/?envType=daily-question&envId=2024-07-06

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int passThePillow(int n, int time) {
        int i=1;
        bool flag=true;
        while(time--){
            if(flag){
                i++;
                if(i==n){
                    flag=false;
                }
            }else{
                i--;
                if(i==1){
                    flag=true;
                }
            }
        }
        return i;
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