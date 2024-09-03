// https://leetcode.com/problems/sum-of-digits-of-string-after-convert/?envType=daily-question&envId=2024-09-03

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int getLucky(string s, int k) {
        int sum=0;
        for(int i=0;i<s.length();i++){
            char c=s.at(i);
            int temp=c-96;
            while(temp>0){
                int rem=temp%10;
                sum+=rem;
                temp/=10;
            }
        }
        int num=sum;
        k--;
        while(k>0){
            sum=0;
            int temp=num;
            while(temp>0){
                int rem=temp%10;
                sum+=rem;
                temp/=10;
            }
            num=sum;
            k--;
        }
        return sum;
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