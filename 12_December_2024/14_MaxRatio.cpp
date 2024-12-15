// https://leetcode.com/problems/maximum-average-pass-ratio/?envType=daily-question&envId=2024-12-15

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
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        
        int n= classes.size();
        priority_queue<pair<double,int>>pq;

        for(int i=0;i<n;i++){

            double temp = ((double)classes[i][0]/classes[i][1]); 
            double temp1= ((double)(classes[i][0]+1)/(classes[i][1]+1)); 
            
            pq.push({temp1-temp,i});
        }

        while(extraStudents--){

             pair<int,int> p = pq.top();
             pq.pop();

             int ind = p.second;

             classes[ind][0]+=1; 
             classes[ind][1]+=1;

            double temp = ((double)classes[ind][0]/classes[ind][1]);
            double temp1= ((double)(classes[ind][0]+1)/(classes[ind][1]+1));

            pq.push({temp1-temp,ind}); 
        }

        double ans=0; 

        for(int i=0;i<n;i++){

            double temp = ((double)classes[i][0]/classes[i][1]);
            
           ans+=temp;
        }

        ans= ans/ (double)n;

        return ans;
    }
};

int main () {
    
    return 0;
}
