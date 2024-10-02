// https://leetcode.com/problems/rank-transform-of-an-array/?envType=daily-question&envId=2024-10-02

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
    vector<int> arrayRankTransform(vector<int> arr) {
        if(arr.size() == 0) return {};

        vector<pair<int,int>> curr;
        for(int i=0; i<arr.size(); i++) {
            curr.push_back({arr[i], i});
        }
        
        sort(curr.begin(), curr.end());

        arr[curr[0].second] = 1; 
        
        for(int i=1; i<arr.size(); i++) {
            if(curr[i].first == curr[i-1].first) {
                arr[curr[i].second] = arr[curr[i-1].second]; 
            }
            else {
                arr[curr[i].second] = arr[curr[i-1].second] + 1; 
            }
        }
        
        return arr;
    }
};

int main () {
    
    return 0;
}
