// https://leetcode.com/problems/product-of-array-except-self/?envType=daily-question&envId=2024-03-15

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output;
        for(int i=0; i<n; i++){
            int product = 1;
            for(int j=0; j<n; j++){
                if(i == j) continue;
                product *= nums[j];
            }
            output.push_back(product);
        }
        return output;
    }
};


int main () {
    
    return 0;
}