// https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/?envType=daily-question&envId=2024-02-15

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        long long perimeter = 0, sides = n;
        
        for(auto it: nums) perimeter += it;

        for(int i=n-1; i>=2; i--){
            if(perimeter <= 2*nums[i]){
                perimeter -= nums[i];
                sides--;
            }
            else break;
        }

        if(sides == 2) return -1;
        return perimeter;
    }
};

int main () {
    
    return 0;
}