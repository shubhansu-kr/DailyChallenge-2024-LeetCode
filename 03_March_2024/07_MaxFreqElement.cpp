// https://leetcode.com/problems/count-elements-with-maximum-frequency/?envType=daily-question&envId=2024-03-08

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto &it: nums) {
            mp[it]++;
        }
        int maxFreq = INT_MIN, count = 0;
        for(auto &it: mp){
            if (it.second > maxFreq){
                count = 1;
                maxFreq = it.second;
            }
            else if (it.second == maxFreq) ++count;
        }
        return count * maxFreq;
    }
};

int main () {
    
    return 0;
}