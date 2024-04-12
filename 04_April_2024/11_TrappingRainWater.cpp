// https://leetcode.com/problems/trapping-rain-water/?envType=daily-question&envId=2024-04-12

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), left=0, right=n-1, res=0, maxleft=0, maxright=0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>=maxleft) maxleft=height[left];
                else res+=maxleft-height[left];
                left++;
            }
            else{
                if(height[right]>=maxright) maxright= height[right];
                else res+=maxright-height[right];
                right--;
            }
        }
        return res;
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