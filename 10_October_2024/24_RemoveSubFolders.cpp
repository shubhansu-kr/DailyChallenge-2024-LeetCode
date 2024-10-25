// https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/?envType=daily-question&envId=2024-10-25

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
    vector<string> removeSubfolders(vector<string>& f) {
         sort(f.begin(),f.end());
         
         vector<string> res;
         unordered_map<string,int> m;

         for(int i=0;i<f.size();i++){
                string cur=f[i];
                string s="";
                bool flg=false;
                for(int c=0;c<cur.size();c++){
                    s+=cur[c];
                    if(cur[c+1]=='/'){
                        if(m.find(s)!=m.end()){
                            flg=true;
                                break;
                        }
                    }
                }
                if(!flg){
                    res.push_back(s);
                }
                m[cur]++;
         }
        return res;
    }
};

int main () {
    
    return 0;
}
