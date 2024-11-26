// https://leetcode.com/problems/find-champion-ii/?envType=daily-question&envId=2024-11-26

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
    int findChampion(int n, vector<vector<int>>& edges) {
        if(n==1) return 0;
        set<int> loser;
        for(int i = 0; i<edges.size();i++){
            loser.insert(edges[i][1]);
        }
        if(loser.size()!=n-1) return -1;

        int i = 0;
        for(auto itr:loser){
            cout<<itr<<endl;
            if(i!=itr){return i;}
            else{i++;}
        }
        return n-1;
        
    }
};

int main () {
    
    return 0;
}
