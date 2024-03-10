// https://leetcode.com/problems/intersection-of-two-arrays/?envType=daily-question&envId=2024-03-10

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // unordered_map<int, int> mp;

        // for(auto &it: nums1) {
        //     if (nums1[it])
        // }

        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());

        unordered_set<int> intersect;
        set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), back_inserter(intersect));

        vector<int> ans(intersect.begin(), intersect.end());

        return ans;
    }
};

int main () {
    
    return 0;
}