// https://leetcode.com/problems/assign-cookies/?envType=daily-question&envId=2024-01-01

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int cookiesNums = s.size();
        if(cookiesNums == 0)  return 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int maxNum = 0;
        int cookieIndex = cookiesNums - 1;
        int childIndex = g.size() - 1;
        while(cookieIndex >= 0 && childIndex >=0){
            if(s[cookieIndex] >= g[childIndex]){
                maxNum++;
                cookieIndex--;
                childIndex--;
            }
            else{
                childIndex--;
            }
        }
        return maxNum;
    }
};

int main () {
    
    return 0;
}