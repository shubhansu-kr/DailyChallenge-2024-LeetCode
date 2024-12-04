// https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/?envType=daily-question&envId=2024-12-04

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
    bool canMakeSubsequence(string mainString, string targetString) {
        bool StatusFlag = false;
        int  targetStrPointer = 0;

        int mainlen = mainString.length();
        int tarLen = targetString.length();

        for(int i = 0 ; i < mainlen ; i++){
            if(targetStrPointer < tarLen ){
                char charAtMainStr = mainString[i];
                char charAtTarStr = targetString[targetStrPointer];
                if(charAtMainStr == 'z' && charAtMainStr != charAtTarStr) charAtMainStr = 'a';
                if(charAtMainStr == charAtTarStr || charAtMainStr+1 == charAtTarStr){
                    StatusFlag = true;
                    targetStrPointer++;
                }else{
                    StatusFlag = false;
                }
            }
        }
        if(targetStrPointer < tarLen) StatusFlag = false;
    return StatusFlag;
    }
};

int main () {
    
    return 0;
}
