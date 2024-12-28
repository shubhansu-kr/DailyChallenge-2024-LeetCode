// https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/?envType=daily-question&envId=2024-12-28

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
    int dp[20002][4];
    int f(int i , vector<int> &prefix , int sub_count , int k) {
        if(i == prefix.size()) {
            if(sub_count == 0)
                return 0;
            return -1e4;
        }
        if(dp[i][sub_count]!=-1)
            return dp[i][sub_count];
        int inc = 0;
        if(i + k < prefix.size() && sub_count != 0)
        inc = (prefix[i + k] - prefix[i - 1]) + f(i + k + 1 , prefix , sub_count-1 , k);
        int exc = 0;
        exc = f(i + 1 , prefix , sub_count , k);
        return dp[i][sub_count] = max(inc , exc);
    }
    vector<int> ans;
    void f2(int i , vector<int> &prefix , int sub_count , int k) {
        if(i == prefix.size() || sub_count == 0) 
            return;
        
        int inc = 0;
        if(i + k < prefix.size() && sub_count != 0)
        inc = (prefix[i + k] - prefix[i - 1]) + f(i + k + 1 , prefix , sub_count-1 , k);

        int exc = 0;
        exc = f(i + 1 , prefix , sub_count , k);

        if(inc >= exc) {
            ans.push_back(i - 1);
            f2(i+k+1 , prefix , sub_count-1 , k);
        }
        else 
            f2(i+1 , prefix , sub_count , k);
    }
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& A, int k) {
        int n = A.size();
        vector<int> prefix(n + 1);
        for(int i = 0 ; i < n ; i++) {
            prefix[i+1] = prefix[i] + A[i];
        }
        memset(dp , -1 , sizeof(dp));
        int maxi = f(1 , prefix , 3 , k-1);
        cout << maxi << endl;
        f2(1 , prefix , 3 , k-1);
        return ans;
    }
};

int main () {
    
    return 0;
}
