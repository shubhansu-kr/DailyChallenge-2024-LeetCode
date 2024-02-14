// https://leetcode.com/problems/rearrange-array-elements-by-sign/?envType=daily-question&envId=2024-02-14

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n-1; ++i)
        {
            if(i % 2) {
                // odd index: negative
                if (nums[i] < 0) continue;

                // get next positive index.
                int index = i+1;
                while(index < n && nums[index] > 0) {
                    ++index;
                }

                // shift the positive element.
                while(index > 0 && index > i) {
                    swap(nums[index], nums[index-1]);
                    --index;
                }
            }
            else {
                // even index: positive
                if (nums[i] > 0) continue;
                
                // get next negative index.
                int index = i+1;
                while(index < n && nums[index] < 0) {
                    ++index;
                }

                // shift the negative element.
                while(index > 0 && index > i) {
                    swap(nums[index], nums[index-1]);
                    --index;
                }
            }
        }
        
        return nums;
    }
};

int main () {
    
    return 0;
}