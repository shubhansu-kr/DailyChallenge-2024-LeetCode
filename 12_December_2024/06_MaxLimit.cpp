// https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/

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

    bool limit(vector<int>& nums, int maxOperations, int mid){
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == mid) continue;
            cnt += nums[i]/mid; 

            if(nums[i]%mid == 0) cnt--; 
        }
        if(cnt <= maxOperations) return true;
        return false;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        int mini = INT_MAX;
        while(low <= high){
            int mid = (low + high)/2;

            if(limit(nums, maxOperations, mid)){
                mini = min(mini, mid);
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return mini;
    }
};

int main () {
    
    return 0;
}
