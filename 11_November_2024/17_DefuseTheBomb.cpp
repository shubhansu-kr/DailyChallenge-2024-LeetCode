// https://leetcode.com/problems/defuse-the-bomb/?envType=daily-question&envId=2024-11-18

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

int decode(int i,vector<int>& code,int k){
    int sum=0;
    i=i+1;
    while(k>0){
        sum=sum+code[i%(code.size())];
        k--;
        i++;
    }
    return sum;
}
int dincode(int i,vector<int>& code,int k){
    int sum=0;
    k=abs(k);
    i=i-1;
    while(k>0){
        if(i<0){
            i=code.size()-1;
        }
        sum=sum+code[i];
        k--;
        i--;
    }
    return sum;
}
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int>result;
        for(int i=0;i<n;i++){
            if(k>0){
                result.push_back(decode(i,code,k));
            }
            else if(k<0){
                result.push_back(dincode(i,code,k));
            }
            else{
                result.push_back(0);
            }
        }
        return result;
    }
};

int main () {
    
    return 0;
}
