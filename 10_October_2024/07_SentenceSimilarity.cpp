// https://leetcode.com/problems/sentence-similarity-iii/?envType=daily-question&envId=2024-10-06

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
    bool areSentencesSimilar(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return areSentencesSimilar(s2, s1);
        } 
        stringstream ss1(s1);
        stringstream ss2(s2);
        string token;

        deque<string> words1;
        deque<string> words2;

        while(ss1 >> token){
            words1.push_back(token);
        }

        while(ss2 >> token){
            words2.push_back(token);
        }

        while(!words1.empty() && !words2.empty() && words1.front() == words2.front()){
            words1.pop_front();
            words2.pop_front();
        }

        while(!words1.empty() && !words2.empty() && words1.back() == words2.back()){
            words1.pop_back();
            words2.pop_back();
        }

        return words1.empty();
    }
};

int main () {
    
    return 0;
}
