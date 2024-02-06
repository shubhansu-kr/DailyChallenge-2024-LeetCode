// https://leetcode.com/problems/group-anagrams/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(auto &it: strs) {
            string str = it;
            sort(str.begin(), str.end());
            mp[str].emplace_back(it);
        }
        vector<vector<string>> ans;
        for(auto &it: mp){
            ans.emplace_back(it.second);
        }
        return ans;
    }
};

int main () {
    
    return 0;
}