// https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/?envType=daily-question&envId=2024-12-02

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
    int isPrefixOfWord(string sentence, string searchWord) {
        if(sentence.length() < searchWord.length()) {
            return - 1;
        }

        int m = searchWord.length();
        int j = 0;
        int notCompare = 0;
        int index = 1;

        for(int i = 0; i < sentence.size(); i++) {
            if(sentence[i] == ' ') {
                notCompare = 0;
                j = 0;
                index++;
                
                continue;
            }

            if(notCompare) {
                continue;
            }

            if(sentence[i] == searchWord[j]) {
                if(++j == m) {
                   return index;
                }
            } else {
                notCompare = 1;
            }
        }

    
        return -1;
    }
};


int main () {
    
    return 0;
}
