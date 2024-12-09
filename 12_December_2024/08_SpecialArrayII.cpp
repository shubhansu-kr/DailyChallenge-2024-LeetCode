// https://leetcode.com/problems/special-array-ii/?envType=daily-question&envId=2024-12-09

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
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        set<int> breakPoints;
        for(int i=1;i<n;i++){
            if(nums[i]%2==0 && nums[i-1]%2==0 || (nums[i-1]%2 && nums[i]%2)){
                breakPoints.insert(i);
                breakPoints.insert(i-1);
            }
        }
        vector<bool> ans;
        for(auto it3:queries){
            int l = it3[0], r = it3[1];
            auto it = breakPoints.lower_bound(l);
            int intervalLen = r-l+1;
            if(it!=breakPoints.end()){
                if(*it==l){
                    auto it2 = breakPoints.upper_bound(l);
                    if(it2!=breakPoints.end()){
                        if(*it2>l && *it2<r){
                            ans.push_back(false);
                        }else if(intervalLen==2 && *it2==r && (nums[l]%2 == nums[r]%2)){//This is a special edge case for interval length == 2, due to usage of lower_bound and upper_bound
                            ans.push_back(false);
                        }else{
                            ans.push_back(true);
                        }
                    }else{
                        ans.push_back(true);
                    }
                }else if(*it >=r){
                    ans.push_back(true);
                }else if(*it>l && *it<r){
                    ans.push_back(false);
                }
            }else{
                ans.push_back(true);
            }
        }
        return ans;
    }
};

int main () {
    
    return 0;
}
