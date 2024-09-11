// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/?envType=daily-question&envId=2024-09-11

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:

    string integerToBinary(int n)
    {
        string ans;
        for (int i = 31; i >= 0; i--) {
            int k = n >> i;
            if (k & 1)
                ans.push_back(1);
            else
                ans.push_back(0);
        }
        return ans;
    }

    int minBitFlips(int start, int goal) {
        string a1 = integerToBinary(start);
        string a2 = integerToBinary(goal);
        int ans = 0;
        int len_a1 = a1.size();
        int len_a2 = a2.size();
        int diff = abs(len_a2-len_a1);
        if(len_a1>len_a2){
            while(diff--){
                a2.insert(0,"0");
            }
        }
        else{
            while(diff--){
                a1.insert(0,"0");
            }
        }
        for(int i=0; i<len_a1; i++){
            if(a1[i]!=a2[i]){
                ans++;
            }
        }
        return ans;
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