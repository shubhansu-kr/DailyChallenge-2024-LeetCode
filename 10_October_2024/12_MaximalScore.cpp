// https://leetcode.com/problems/maximal-score-after-applying-k-operations/?envType=daily-question&envId=2024-10-14

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution 
{
public:
    long long maxKelements(vector<int>& nums, int k) 
    {
        priority_queue<int> pq(nums.begin(),nums.end());

        long long val = 0;
        for(int i=0;i<k;i++)
        {
            int x = pq.top();
            val+=x;
            if( x == 1)
            {
                val+=(k-1-i);
                break;
            }
            pq.pop();
            pq.push((x+2)/3);
        }
        return val;
    }
};

int main () {
    
    return 0;
}
