// https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/?envType=daily-question&envId=2024-12-16

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

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while(k--){
            int minIndex = 0;
            for(int i=0; i<nums.size(); i++){
                if(nums[i] < nums[minIndex]){
                    minIndex = i;
                }
            }
            nums[minIndex] = nums[minIndex] * multiplier;
        }
        return nums;
    }
};

int main () {
    
    return 0;
}
