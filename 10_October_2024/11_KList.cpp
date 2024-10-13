// https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/?envType=daily-question&envId=2024-10-13

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
    vector<int> smallestRange(vector<vector<int>>& nums) {
       int maxVal= INT_MIN;
       priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>minheap;
       int k=nums.size();
       for(int i=0; i<k; ++i){
        maxVal=max(maxVal,nums[i][0]);
        minheap.push({nums[i][0],i,0});
       }
       int min_L=0;
       int max_R=INT_MAX;
       while(1){
       auto curr=minheap.top();
       minheap.pop();
       int r= curr[1];
       int c= curr[2];
       int currVal=curr[0];
       if(max_R-min_L >maxVal-currVal){
       min_L= currVal;
       max_R=maxVal;
       }
       if(c<nums[r].size()-1){
        minheap.push({nums[r][c+1],r,c+1});
        maxVal=max(maxVal,nums[r][c+1]);
       }
       else{
        break;
       }
       }
       return {min_L,max_R};

   
    }
};

int main () {
    
    return 0;
}
