// https://leetcode.com/problems/number-complement/?envType=daily-question&envId=2024-08-22

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int findComplement(int num) {
        string number=to_string(num);
        string binary_number="";
        int temp, i=0;
        
        while(num>0)
        {
            binary_number = (num % 2 == 0 ? "0" : "1") + binary_number;
            num=num/2;
        }

        while(binary_number[i]!='\0')
        {
            if(binary_number[i]=='0')
            binary_number[i]='1';

            else
            binary_number[i]='0';

            i++;
        }

        int ans=stoi(binary_number, nullptr , 2);
        return (ans);
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