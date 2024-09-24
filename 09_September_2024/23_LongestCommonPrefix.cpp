// https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/?envType=daily-question&envId=2024-09-24

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
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st ; 

        for(int val : arr1 ){
            while(!st.count(val) &&  val > 0 ){
                st.insert(val);
                val = val/10 ; 
            }
        }
        int result = 0 ;
        for(int num : arr2){
            while(!st.count(num) && num > 0 ){
                num /= 10 ; 
            }
            if(num > 0 ){
                result = max(result , static_cast<int>(log10(num))+1);
            }
        }
        return result;
    }
};
int main () {
    
    return 0;
}
