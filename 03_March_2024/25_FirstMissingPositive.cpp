// https://leetcode.com/problems/first-missing-positive/?envType=daily-question&envId=2024-03-26

#include <bits/stdc++.h>
using namespace std ;

class Solution
{
public:
    int firstMissingPositive(int A[], int n)
    {
        for(int i = 0; i < n; ++ i)
            while(A[i] > 0 && A[i] <= n && A[A[i] - 1] != A[i])
                swap(A[i], A[A[i] - 1]);
        
        for(int i = 0; i < n; ++ i)
            if(A[i] != i + 1)
                return i + 1;
        
        return n + 1;
    }
};

class Solution {
    // WA
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int ans = n + 1;

        for(auto &it: nums) {
            if (it < 0){
                it = abs(it);
            }
            else if (it == 0){
                it = ans;
            }
            else if (it < ans) {
                nums[it-1] = -(abs(nums[it-1]));
            }
        }

        for(int i = 0; i < n; ++i) {
            if (nums[i] > 0) return i+1;
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