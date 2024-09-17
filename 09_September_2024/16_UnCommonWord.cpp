// https://leetcode.com/problems/uncommon-words-from-two-sentences/?envType=daily-question&envId=2024-09-17

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
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> s1Words = splitSentence(&s1);
        vector<string> s2Words = splitSentence(&s2);

        map<string, int> s1Occurs = getOccurrences(&s1Words);
        map<string, int> s2Occurs = getOccurrences(&s2Words);

        vector<string> uncommons;
        getUncommons(&uncommons, &s1Occurs, &s2Occurs);
        getUncommons(&uncommons, &s2Occurs, &s1Occurs);
        return uncommons;
    }

    vector<string> splitSentence(string* s1)
    {
        vector<string> tokens;
        stringstream ss(*s1);

        string token;
        while(getline(ss, token, ' '))
        {
            tokens.push_back(token);
        }

        return tokens;
    }

    map<string, int> getOccurrences(vector<string> *words)
    {
        map<string, int> occurs;
        for(string word : *words)
        {
            auto match = occurs.find(word);
            if(match == occurs.end())
                occurs[word] = 1;
            else
                occurs[word]++;
        }
        return occurs;
    }

    void getUncommons(vector<string>* uncommons, map<string, int>* occurs1, map<string, int>* occurs2)
    {
        for(auto pair : *occurs1)
        {
            if(pair.second != 1)
                continue;

            auto match = occurs2->find(pair.first);

            if(match != occurs2->end())
                continue;

            uncommons->push_back(pair.first);
        }
    }
};

int main () {
    
    return 0;
}
