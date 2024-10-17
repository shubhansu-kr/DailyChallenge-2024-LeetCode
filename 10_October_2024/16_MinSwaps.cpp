// https://leetcode.com/problems/maximum-swap/?envType=daily-question&envId=2024-10-17

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
    int maximumSwap(int num) {
        string nums = to_string(num);
        int n = nums.size();

        vector<int>ind(n);

        ind[n - 1] = n - 1;

        for(int i = n - 2; i >= 0; i--){
            if (nums[i] > nums[ind[i + 1]]) {
                ind[i] = i;
            } else {
                ind[i] = ind[i + 1];
            }
        }
        for (int i = 0; i < n; ++i){
            if(nums[i] < nums[ind[i]]){
                swap(nums[i], nums[ind[i]]);
                break;
            }
        }
        return stoi(nums);
        
    }
};

int main () {
    
    return 0;
}
