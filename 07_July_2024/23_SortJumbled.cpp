// https://leetcode.com/problems/sort-the-jumbled-numbers/?envType=daily-question&envId=2024-07-24

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    unordered_map<int, int> mp;
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        for(auto &it: nums){
            int currentNumber = it;
            int mappedNumber = 0;
            int multiplier = 1;
            while(true) {
                int digit = currentNumber % 10;
                mappedNumber = mapping[digit] * multiplier + mappedNumber; 
                multiplier *= 10;
                currentNumber /= 10;

                if (!currentNumber) break;
            }
            mp[it] = mappedNumber;
        }

        sort(nums.begin(), nums.end(), [this](int i, int j) {
            return mp[i] < mp[j];
        });
        return nums;
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