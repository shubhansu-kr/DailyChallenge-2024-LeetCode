// https://leetcode.com/problems/fraction-addition-and-subtraction/?envType=daily-question&envId=2024-08-23

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int gcd(int a,int b){
            return b == 0 ? a : gcd(b, a % b);    
    }
    string fractionAddition(string expression) {
        vector<int>numerators;
        vector<int>denominators;
        int type=1;
        int isNum=1;
        int num=0;
        for(auto ch:expression){
            if(ch=='+'){
                if(num!=0){
                    denominators.push_back(type*num);
                }
                num=0;
                type=1;
                continue;
            }
            if(ch=='-'){
                 if(num!=0){
                    denominators.push_back(type*num);
                }
                type=-1;
                num=0;
                continue;
            }
            if(ch=='/'){
                 if(num!=0){
                    numerators.push_back(type*num);
                }
                type=1;
                num=0;
                continue;
            }
            int ind=ch-'0';
            num=num*10+ind;
        }
        denominators.push_back(type*num);
        int ans1=0;
        for(int i=0;i<numerators.size();i++){
            ans1+=(30240/denominators[i])* numerators[i];
        }
        int numer=gcd(abs(ans1),30240);
        ans1=ans1/numer;
        int deno=30240/numer;
        return to_string(ans1)+"/"+to_string(deno);
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