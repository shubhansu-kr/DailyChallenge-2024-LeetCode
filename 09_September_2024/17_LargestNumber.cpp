// https://leetcode.com/problems/largest-number/?envType=daily-question&envId=2024-09-18

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
    static bool special_compare(const int a,const int b){
        int num1 = 1, num2 = 1;
        if(a > 0) num1 = log10(a)+1;
        if(b > 0) num2 = log10(b)+1;
        return a*pow(10, (int)num2) +b > b*pow(10, (int)num1) +a;
    }
    string largestNumber(vector<int>& nums) {
        string ans = "";
        sort(nums.begin(), nums.end(), special_compare);
        if(nums[0] == 0)return "0";
        for(const auto& num : nums)ans = ans + to_string(num);
        return ans;
    }
};

int main () {
    
    return 0;
}
