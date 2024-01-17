// https://leetcode.com/problems/unique-number-of-occurrences/?envType=daily-question&envId=2024-01-17

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> freq(2001);
        for(auto &it: arr){
            freq[it+1000]++;
        }
        unordered_set<int> st;
        for(auto &it: freq){
            if (it == 0) continue;
            if(st.count(it)) return false;
            else st.insert(it);
        }
        return true;
    }
};

int main () {
    
    return 0;
}