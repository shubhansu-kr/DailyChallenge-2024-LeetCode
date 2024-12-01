// https://leetcode.com/problems/check-if-n-and-its-double-exist/?envType=daily-question&envId=2024-12-01

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
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> st;
        for(auto &it: arr){
            if (it == 0){
                if (st.count(it)) return true;
            }
            st.insert(it);
        }
        for(auto &it: arr){
            if (it && st.count(it*2)) return true;
        }
        return false;
    }
};

int main () {
    
    return 0;
}
