// https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/?envType=daily-question&envId=2024-11-20

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    int takeCharacters(string s, int k) {
        int acount=0,bcount=0,ccount=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a')
            acount++;
            else if(s[i]=='b')
            bcount++;
            else
            ccount++;
        }
        if(acount<k || bcount<k || ccount<k)
        return -1;
        int max_size=0,n=s.size();
        int i=0,j=0;
        while(i<s.size()){
            if(s[i]=='a')
                acount--;
            else if(s[i]=='b')
                bcount--;
            else
                ccount--;
            while(acount<k || bcount<k || ccount<k){
                if(s[j]=='a')
                    acount++;
                else if(s[j]=='b')
                    bcount++;
                else
                    ccount++;
                j++;
            }
            max_size=max(max_size,i-j+1);
            i++;
        }
        return n-max_size;
    }
};

int main () {
    
    return 0;
}
