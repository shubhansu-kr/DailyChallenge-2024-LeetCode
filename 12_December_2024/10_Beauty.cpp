// https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/?envType=daily-question&envId=2024-12-11

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
    static int maximumBeauty(vector<int>& nums, int k) {
        int freq[100001]={0};
        int xMax=0, xMin=1e6;
        for(int x: nums){
            freq[x]++;
            xMax=max(x, xMax);
            xMin=min(x, xMin);
        }
        int cnt=0, maxCnt=0;
        for(int l=xMin, r=xMin; r<=xMax; r++){
            cnt+=freq[r];
            while(r-l>2*k){
                cnt-=freq[l];
                l++;
            }
            maxCnt=max(maxCnt, cnt);
        }
        return maxCnt;
    }
};

int main () {
    
    return 0;
}
