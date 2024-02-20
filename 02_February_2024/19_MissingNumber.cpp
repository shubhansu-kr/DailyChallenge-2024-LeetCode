// https://leetcode.com/problems/missing-number/?envType=daily-question&envId=2024-02-20

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = n * (n + 1) / 2;
        for (int a : nums)
        {
            sum -= a;
        }
        return sum;
    }
};

int main () {
    
    return 0;
}