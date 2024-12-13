// https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/?envType=daily-question&envId=2024-12-13

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
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool> marked(n, false); 
        vector<pair<int, int>> elements;
       
        for (int i = 0; i < n; ++i) {
            elements.push_back({nums[i], i});
        }
    
        sort(elements.begin(), elements.end());
    
        long long  score = 0;
    
        for (const auto& [value, index] : elements) {
            if (!marked[index]) { 
                score += value;  
                marked[index] = true; 
    
               
                if (index > 0) {
                    marked[index - 1] = true;
                }
    
             
                if (index < n - 1) {
                    marked[index + 1] = true;
                }
            }
        }
    
        return score;
        
    }
};

int main () {
    
    return 0;
}
