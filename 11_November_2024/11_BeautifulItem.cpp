// https://leetcode.com/problems/most-beautiful-item-for-each-query/?envType=daily-question&envId=2024-11-12

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
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        const int n = items.size(), m = queries.size();
        vector<unsigned long long> PB(n);
        for(int i=0; i<n; i++)
            PB[i]=((unsigned long long)items[i][0]<<32)+items[i][1];
        sort(PB.begin(), PB.end());

        vector<int> mostBeauty(n);
        partial_sum(PB.begin(), PB.end(), mostBeauty.begin(), [&](int sum, auto x){
            return sum=max(sum, (int)(x&INT_MAX));
        });

        vector<int> ans(m);
        for_each(queries.begin(), queries.end(), [&, i=0](int query) mutable{
             unsigned long long target=((unsigned long long)query<<32)+UINT_MAX;
            // Use upper_bound to find the first item with a price > query
            int j = upper_bound(PB.begin(), PB.end(), target)-PB.begin();
            // If j is 0, no items have price <= query
            ans[i++]= (j == 0) ?0: mostBeauty[j-1];
        });
        return ans;
    }
};


int main () {
    
    return 0;
}
