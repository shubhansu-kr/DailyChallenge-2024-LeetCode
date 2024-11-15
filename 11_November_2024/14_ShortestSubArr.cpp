// https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/?envType=daily-question&envId=2024-11-15

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
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int low=0;
        int n=arr.size();
        int high=arr.size()-1;
        int cnt=0;
        while(low<n-1 && arr[low]<=arr[low+1]){
            low++;
        }
        while(high>0 && arr[high]>=arr[high-1]){
            high--;
        }
        if(low==n-1) return 0;
        
        int ans=min(n-low-1,high);
        int i=0,j=high;
        while(i<=low && j<n){
            if(arr[i]<=arr[j]){
                ans=min(ans,j-i-1);
                i++;
            }
            else{
                j++;
            }
        }
        return ans;
    }
};

int main () {
    
    return 0;
}
