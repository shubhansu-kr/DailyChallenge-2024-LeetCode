// https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/?envType=daily-question&envId=2024-10-18

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
    int countMaxOrSubsets(vector<int> &nums)
    {
        int n = nums.size();
        int maxOR = -1, tempOR = 0;
        int freq = 0;
        countOR(nums, tempOR, maxOR, freq);
        return freq;
    }
    void countOR(vector<int> &nums, int &tempOR, int &maxOR, int &freqOR, int i = 0)
    {
        if (i == nums.size())
        {
            if (maxOR == tempOR)
            {
                ++freqOR;
            }
            else if (maxOR < tempOR)
            {
                maxOR = tempOR;
                freqOR = 1;
            }
            return;
        }
        // Pick
        int temp = (tempOR | nums[i]);
        countOR(nums, temp, maxOR, freqOR, i + 1);
        // Not Pick
        countOR(nums, tempOR, maxOR, freqOR, i + 1);
    }
};

int main () {
    
    return 0;
}
