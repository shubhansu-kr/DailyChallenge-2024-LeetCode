// https://leetcode.com/problems/all-oone-data-structure/?envType=daily-question&envId=2024-09-29

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class AllOne {
public:
    map<string, int> mp; 
    set<pair<int, string>> freqSet; 

    AllOne() {}

    void inc(string key) {
        if(mp.find(key) != mp.end()) {
            freqSet.erase({mp[key], key});
        }
        mp[key]++;
        freqSet.insert({mp[key], key});
    }

    void dec(string key) {
        if(mp.find(key) != mp.end()) {
            freqSet.erase({mp[key], key});
            mp[key]--;
            if(mp[key] == 0) {
                mp.erase(key);
            } else {
                freqSet.insert({mp[key], key});
            }
        }
    }

    string getMaxKey() {
        if(freqSet.empty()) return "";  
        return freqSet.rbegin()->second;
    }

    string getMinKey() {
        if(freqSet.empty()) return ""; 
        return freqSet.begin()->second;
    }
};

int main () {
    
    return 0;
}
