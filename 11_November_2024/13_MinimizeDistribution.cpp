// https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/?envType=daily-question&envId=2024-11-14

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
    int minimizedMaximum(int n, vector<int>& quantities) {
        if (n == 1) return quantities[0];
        int sum = 0;
        for (int i = 0; i < quantities.size(); i++){
            sum += quantities[i];
            if(sum >= n) break;
            else if (sum < n && i == quantities.size() - 1) return 1;
        }
       int left = 0;
       int right = 100000;
       int min_til_now = 1000000;
        while (left <= right) {
            int mid = (right + left) / 2;
            int minStoreNeed = 0;
            for (int it: quantities){
                int temp = static_cast<int>(ceil((double)it / mid));
                if (temp == 0) minStoreNeed ++;
                else minStoreNeed += temp;
            }
            if (minStoreNeed <= n){
                min_til_now = min(min_til_now, mid);
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return min_til_now;
    }
};

int main () {
    
    return 0;
}
