// https://leetcode.com/problems/two-best-non-overlapping-events/?envType=daily-question&envId=2024-12-08

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {

    int search_array(vector<vector<int>>&events,int target,int low,int high){
        while(high - low > 1){
            int mid = (low + high)>>1;
            if(events[mid][0] >= target){
                high = mid;
            }else{
                low = mid;
            }
        }

        if(events[low][0] >= target)return low;
        if(events[high][0] >= target)return high;
        return -1;
    }

public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end(),[](vector<int>&a,vector<int>&b){
            if(a[0] < b[0])return true;
            if(a[0] > b[0])return false;
            return a[2] > b[2];
        });

        int n = events.size();
        vector<int>suffix(n);
        suffix[n-1] = events[n-1][2];
        for(int i = n-2 ; i >= 0 ; i--){
            suffix[i] = max(suffix[i+1],events[i][2]);
        } 

        int max_answer = suffix[0];
        for(int i = 0 ; i < n-1 ; i++){
            int next_index = search_array(events,events[i][1]+1,i+1,n-1);
            if(next_index != -1){
                max_answer = max(max_answer,events[i][2] + suffix[next_index]);
            }
        }
        return max_answer;
    }
};

int main () {
    
    return 0;
}
