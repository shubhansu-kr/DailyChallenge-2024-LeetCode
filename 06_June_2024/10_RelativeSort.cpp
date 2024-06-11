// https://leetcode.com/problems/relative-sort-array/?envType=daily-question&envId=2024-06-11

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int k = 0;
        for (int i = 0; i < arr2.size(); i++)
        {
            for (int j = 0; j < arr1.size(); j++)
            {
                if (arr2[i] == arr1[j])
                {
                    swap(arr1[k], arr1[j]);
                    k++;
                }
            }
        }
        sort(arr1.begin() + k, arr1.end());
        return arr1;
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