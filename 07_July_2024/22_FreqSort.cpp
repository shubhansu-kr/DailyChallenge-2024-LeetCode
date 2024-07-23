// https://leetcode.com/problems/sort-array-by-increasing-frequency/?envType=daily-question&envId=2024-07-23

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {

        vector<int> result;
        map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }

        int n=mp.size();
        auto temp=mp.begin();
        
        while(n--){
            int min=INT_MAX;
            for(auto it=mp.begin();it!=mp.end();it++){
                if(it->second<=min and it->second>0){
                    if(it->second==min and it->first>temp->first){
                        temp=it;
                        min=it->second;
                    }
                    else{
                        min=it->second;
                        temp=it;
                    }
                }
            }

            while(min--){
                result.push_back(temp->first);
            }
            temp->second=0;
        }

        return result;
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