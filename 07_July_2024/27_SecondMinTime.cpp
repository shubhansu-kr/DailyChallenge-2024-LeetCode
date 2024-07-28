// https://leetcode.com/problems/second-minimum-time-to-reach-destination/?envType=daily-question&envId=2024-07-28

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
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<int> adj[n+1];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        queue<pair<int,int>> q;
        q.push({1,0});

        vector<int> dist1(n+1,INT_MAX);
        vector<int> dist2(n+1,INT_MAX);

        dist1[1]=0;
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            if(it.second && (it.second/change)%2)
                it.second = ((it.second/change)*change) + change;
            
            for(auto v:adj[it.first]){
                int temp = it.second + time;
                if(dist1[v] > temp){
                    dist2[v]= dist1[v];
                    dist1[v] = temp;
                    q.push({v,dist1[v]});
                }
                else if(temp > dist1[v] && temp < dist2[v]){
                    dist2[v] = temp;
                    q.push({v,dist2[v]});
                }
            }
        }
        return dist2[n];
    }
};

int main () {
    
    return 0;
}