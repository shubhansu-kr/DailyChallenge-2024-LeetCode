// https://leetcode.com/problems/number-of-laser-beams-in-a-bank/?envType=daily-question&envId=2024-01-03

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int beam = 0, data = 0;
        for (int i = 0; i < bank.size(); i++)
        {
            int count = 0;
            for (int j = 0; j < bank[i].length(); j++)
            {
                if (bank[i][j] == '1')
                {
                    count++;
                }
            }
            if (count)
            {
                beam += count * (data);
                data = count;
            }
        }
        return beam;
    }
};

int main () {
    
    return 0;
}