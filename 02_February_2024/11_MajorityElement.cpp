// https://leetcode.com/problems/majority-element/?envType=daily-question&envId=2024-02-12

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hash;
        int res = 0;
        int majority = 0;

        for (int n : nums) {
            hash[n] = 1 + hash[n];
            if (hash[n] > majority) {
                res = n;
                majority = hash[n];
            }
        }

        return res;        
    }
};

int main () {
    
    return 0;
}