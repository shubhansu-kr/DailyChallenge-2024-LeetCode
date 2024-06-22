// https://leetcode.com/problems/count-number-of-nice-subarrays/?envType=daily-question&envId=2024-06-22

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        
        vector<int> oddIndex;

        for (int i = 0; i < n; ++i)
        {
            if (nums[i] % 2) oddIndex.emplace_back(i);
        }
        
        for (int i = k-1; i < oddIndex.size(); ++i)
        {
            int b = oddIndex[i], a = oddIndex[i-k+1];
            
            int p = a,  q = n-b-1;
            if (i < oddIndex.size()-1) q = oddIndex[i+1] - b - 1; 
            if (i-k >= 0) p = a - oddIndex[i-k] -1;

            ans += ((p*q) + (p+q) + 1);
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