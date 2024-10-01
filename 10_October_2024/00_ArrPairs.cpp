// https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/?envType=daily-question&envId=2024-10-01

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
    bool canArrange(vector<int>& arr, int k) 
    {
        vector<int>mp(k,0);
        for(int &v:arr)
        {
            int rem = (v%k + k) % k; 
            mp[rem]++;;
        }
        if(mp[0]%2!=0) return false;
        for(int i=1; i<=k/2; i++)
        {
            int half = k-i;
            if(mp[half]!=mp[i]) return false;
        }
        return true;
    }
};

int main () {
    
    return 0;
}
