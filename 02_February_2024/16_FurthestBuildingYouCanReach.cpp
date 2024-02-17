// https://leetcode.com/problems/furthest-building-you-can-reach/?envType=daily-question&envId=2024-02-17

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        for (int i = 0; i < heights.size() - 1; i++)
        {
            int diff = heights[i + 1] - heights[i];
            if (diff > 0)
                pq.push(-diff);
            if (pq.size() > ladders)
            {
                bricks += pq.top();
                pq.pop();
            }
            if (bricks < 0)
                return i;
        }
        return heights.size() - 1;
    }
};

int main () {
    
    return 0;
}