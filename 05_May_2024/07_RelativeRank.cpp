// https://leetcode.com/problems/relative-ranks/?envType=daily-question&envId=2024-05-08

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int> > pq;
        for(int i=0;i<score.size();i++)
        {
            pq.push(make_pair(score[i],i));
        }
        vector<string> res(score.size(),"");
        int count = 1;
        for(int i=0; i<score.size();i++)
        {
            if(count==1) {res[pq.top().second] = "Gold Medal"; count++;}
            else if(count==2) {res[pq.top().second] = "Silver Medal"; count++;}
            else if(count==3) {res[pq.top().second] = "Bronze Medal"; count++;}
            else {res[pq.top().second] = to_string(count); count++;}
            pq.pop();
        }
        return res;
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