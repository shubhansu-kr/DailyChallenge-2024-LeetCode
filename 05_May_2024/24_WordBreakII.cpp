// https://leetcode.com/problems/word-break-ii/?envType=daily-question&envId=2024-05-25

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:

    vector<string> ans;

    void solve(int i, string &sentence, string &givenString, unordered_map<string, bool> &doesExist) {
        if (i >= givenString.size()) {
            ans.push_back(sentence);
            return;
        }

        for (int j = i + 1; j <= i + 10  &&  j <= givenString.size(); j++) {
            string word = givenString.substr(i, j - i);
            if (doesExist.find(word) != doesExist.end()) {
                if (sentence.size() == 0) {
                    sentence = word;
                } else {
                    sentence += " " + word;
                }
                solve(j, sentence, givenString, doesExist);
                int x = 0;
                while (x < word.size()) {
                    x++;
                    sentence.pop_back();
                }

                if (sentence.size() > 0) {
                    sentence.pop_back();
                }
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        string sentence = "";
        unordered_map<string, bool> doesExist;
        for (auto x: wordDict) {
            doesExist[x] = true;
        }

        ans.clear();
        solve(0, sentence, s, doesExist);
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