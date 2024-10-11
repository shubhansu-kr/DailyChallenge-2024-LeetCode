// https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/?envType=daily-question&envId=2024-10-11

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

#define pii pair<int,int>
#define ff first
#define ss second
class Solution {
public:

    int smallestChair(vector<vector<int>>&mat, int t) 
    {
        set<int>s;
        for(int i=0;i<mat.size();i++)s.insert(i);
        vector<pair<pair<int,int>,int>>v;
        for(int i=0;i<mat.size();i++)
        {
            v.push_back({{mat[i][0],mat[i][1]},i});
        }
        sort(v.begin(),v.end());
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        for(int i=0;i<v.size();i++)
        {
            while(!pq.empty()&&pq.top().ff<=v[i].ff.ff)
            {
                s.insert(pq.top().ss);
                pq.pop();
            }
            auto it=*s.begin();
            if(t==v[i].ss)
            {
                return it;
            }
            pq.push({v[i].ff.ss,it});
            s.erase(it);
        }
        return 0;
    }
};

int main () {
    
    return 0;
}
