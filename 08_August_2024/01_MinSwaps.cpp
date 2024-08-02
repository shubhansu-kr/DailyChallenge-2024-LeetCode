// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/?envType=daily-question&envId=2024-08-02

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int count = 0; 
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) {
                count++;
            }
        }

        vector<int> arr(nums.size() * 2);
        for(int i = 0; i < nums.size(); i++) {
            arr[i] = nums[i];
            arr[i + nums.size()] = nums[i];
        }

        int maxOnes = 0;
        int currentOnes = 0;
        for(int i = 0; i < count; i++) {
            if(arr[i] == 1) {
                currentOnes++;
            }
        }
        maxOnes = currentOnes;

        for(int i = 1; i < nums.size(); i++) {
            if(arr[i - 1] == 1) {
                currentOnes--;
            }
            if(arr[i + count - 1] == 1) {
                currentOnes++;
            }
            maxOnes = max(maxOnes, currentOnes);
        }

        return count - maxOnes;
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