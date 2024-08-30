// https://leetcode.com/problems/modify-graph-edge-weights/?envType=daily-question&envId=2024-08-30

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    typedef long long ll;
    const int LARGE_VALUE = 2e9;
    int shortestDistance(vector<vector<int>>& edges,int n,int source, int destination)
    {
        unordered_map<ll,vector<pair<ll,ll>>>Adj;
        for(vector<int>& edge:edges)
        {
            if(edge[2]!=-1)
            {
                Adj[edge[0]].push_back({edge[1],edge[2]});
                Adj[edge[1]].push_back({edge[0],edge[2]});
            }
        }
        vector<ll>dist(n,INT_MAX);
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
        pq.push({0,source});
        dist[source]=0;
        while(!pq.empty())
        {
            ll dis=pq.top().first;
            ll node=pq.top().second;
            pq.pop();
            for(auto itr:Adj[node])
            {
                ll edgeWeight=itr.second;
                if(dis+edgeWeight<dist[itr.first])
                {
                   dist[itr.first]=dis+edgeWeight;
                   pq.push({dist[itr.first],itr.first}); 
                }
            }
        }
        return dist[destination];
    }
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        ll currCost=shortestDistance(edges,n,source,destination);
        if(currCost<target)
        {
            return {};
        }
        bool matchedTarget=(currCost==target);
        for(vector<int>& edge:edges)
        {
            if(edge[2]==-1)
            {
                edge[2]=(matchedTarget==true)?LARGE_VALUE:1;
                if(matchedTarget!=true)
                {
                    ll newShortestDistance=shortestDistance(edges,n,source,destination);
                    if(newShortestDistance<=target)
                    {
                        matchedTarget=true;
                        edge[2]+=(target-newShortestDistance);
                    }
                }
            }
        }
        if(!matchedTarget)
        {
            return {};
        }
        return edges;
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