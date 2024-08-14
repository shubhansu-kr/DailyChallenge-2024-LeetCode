// https://leetcode.com/problems/find-k-th-smallest-pair-distance/?envType=daily-question&envId=2024-08-14

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int smallestDistancePair(vector<int>& a, int k) {
        sort(begin(a),end(a));
        vector<int>v(a[a.size()-1]+1);
        int n=a.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int diff=abs(a[j]-a[i]);
                v[diff]++;
            }
        }
        for(int i=0;i<v.size();i++){
            k-=v[i];
            if(k<=0)return i;
        }
        return 1;
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