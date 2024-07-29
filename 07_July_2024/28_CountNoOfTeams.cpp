// https://leetcode.com/problems/count-number-of-teams/?envType=daily-question&envId=2024-07-29

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans=0;
        for(int i=0;i<rating.size();i++){
            for(int j=i+1;j<rating.size();j++){
                if(rating[i]<rating[j]){
                    for(int k=j+1;k<rating.size();k++){
                        if(rating[j]<rating[k]){
                            ans++;
                            continue;
                        }
                    }
                }
                else if(rating[i]>rating[j]){
                    for(int k=j+1;k<rating.size();k++){
                        if(rating[j]>rating[k]){
                            ans++;
                            continue;
                        }
                    }
                }
            }
        }
        return ans;
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