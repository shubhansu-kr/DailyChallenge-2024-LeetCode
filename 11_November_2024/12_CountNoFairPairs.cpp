// https://leetcode.com/problems/count-the-number-of-fair-pairs/?envType=daily-question&envId=2024-11-13

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

    int lower_lim(vector<int>& nums, int elem, int startIdx, int lower){

        int i = startIdx, j = nums.size()-1, ans = -1;

        while(i<= j){

            int mid = (i+j)/2;

            if(nums[mid] + elem >= lower){
                ans = mid;
                j = mid-1;
            }else{
                i = mid+1;
            }
        }

        return ans;
    }

    int upper_lim(vector<int>& nums, int elem, int startIdx, int upper){

        int i = startIdx, j = nums.size()-1, ans = -1;

        while(i<= j){

            int mid = (i+j)/2;

            if(nums[mid] + elem <= upper){
                ans = mid;
                i = mid+1;
            }else{
                j = mid-1;
            }
        }

        return ans;
    } 
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        long long ans = 0;

        for(int i = 0; i < n; i++){

            int lower_idx = lower_lim(nums, nums[i], i+1, lower);      

            int upper_idx = upper_lim(nums, nums[i], i+1, upper);      

            if(lower_idx != -1 && upper_idx != -1){
                ans += (upper_idx - lower_idx+1);
            }
        }

        return ans;
    }
};

int main () {
    
    return 0;
}
