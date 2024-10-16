// https://leetcode.com/problems/longest-happy-string/?envType=daily-question&envId=2024-10-16

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
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        if(a)pq.push({a,'a'});
        if(b)pq.push({b,'b'});
        if(c)pq.push({c,'c'});
        string s="";
        char last='*';
        while(!pq.empty()){
           auto [count,el]= pq.top();
           pq.pop();
           if(el!=last){
            if(count>=2){
                s+=el;
                s+=el;
                count-=2;
            }
            else{
                s+=el;
                count--;
            }
            last=el;
           }
           else{
            if(pq.empty()) return s;
            auto [count2,el2]= pq.top();
            pq.pop();
            if(count2>=2){
                if(count/2+count%2>=count2/2){
                    s+=el2;
                    count2--;
                }
                else{
                    s+=el2;
                    s+=el2;
                    count2-=2;
                }
            }
            else{
                s+=el2;
                count2--;
            }
            last=el2;
            if(count2)pq.push({count2,el2});
           }
           if(count)pq.push({count,el});
        }
        return s;
    }
};

int main () {
    
    return 0;
}
