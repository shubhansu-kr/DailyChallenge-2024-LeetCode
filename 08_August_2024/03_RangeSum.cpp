// https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/?envType=daily-question&envId=2024-08-04

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> arr ;
        for ( int i = 0 ; i<n ;i++)
        {
            int sum = 0 ;

            for ( int j = i ; j<n ; j++)
            {
                sum += nums[j];
                arr.push_back(sum);
            }
        }
        sort(arr.begin(), arr.end());
        int totalsum = 0 ;
        int MOD = 1000000007;
        for ( int i = left-1 ;  i<right ; i++)
        {
            totalsum =  (totalsum + arr[i]) % MOD;
        }
        return totalsum ;        
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