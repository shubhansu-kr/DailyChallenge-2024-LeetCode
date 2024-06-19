// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/?envType=daily-question&envId=2024-06-19

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int s = 0 , e = 1e9;
        int mid = s+(e-s)/2 , ans = -1;
        while(s<=e){
            int con = 0 , buk = 0;
            for(int i=0;i<bloomDay.size();i++){
                if(bloomDay[i]<=mid){
                    con++;
                    if(con>=k){
                    buk++;
                    con = 0;
                    }
                }
                else con = 0;
            }
            if(buk>=m){
                ans = mid;
                e = mid-1;
            }
            else s = mid+1;
            mid = s+(e-s)/2;
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