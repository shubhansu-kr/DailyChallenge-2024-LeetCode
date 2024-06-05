// https://leetcode.com/problems/find-common-characters/?envType=daily-question&envId=2024-06-05

#include <bits/stdc++.h>
using namespace std ;

class Solution {
    int frequency(string s, char a)
    {
        int count = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == a)
            {
                count++;
            }
        }
        return count;
    }
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;
        set<char> uni;
        for (int i = 0; i < words[0].length(); i++)
        {
            if (!uni.count(words[0][i]))
            {
                uni.insert(words[0][i]);
                int min = frequency(words[0], words[0][i]);
                for (int j = 1; j < words.size(); j++)
                {
                    int f = frequency(words[j], words[0][i]);
                    if (f < min)
                    {
                        min = f;
                        if (min == 0)
                        {
                            break;
                        }
                    }
                }
                while (min)
                {
                    string s;
                    s += words[0][i];
                    ans.push_back(s);
                    min--;
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