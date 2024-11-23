// https://leetcode.com/problems/rotating-the-box/?envType=daily-question&envId=2024-11-23

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution
{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
    {
        if (box.size() == 1ul && box.front().size() == 1ul)
            return box;

        size_t row;
        int    col;
        size_t nextStoneOrObstacle;
        for (row = 0ul; row != box.size(); ++row)
        {
            nextStoneOrObstacle = box.front().size();
            for (col = box.front().size()-1ul; col != -1; --col)
                switch (box[row][col])
                {
                case '#':
                    box[row][col] = '.';
                    box[row][--nextStoneOrObstacle] = '#';
                    break;
                case '*':
                    nextStoneOrObstacle = col;
                }
        }

        const size_t rowsMinus1 = box.size()-1ul;
        if (box.size() == box.front().size())
        {
            const size_t halfRows = box.size() >> 1ul;
            for (row = 0ul; row != halfRows; ++row)
                box[row].swap(box[rowsMinus1-row]);
            for (row = 1ul; row != box.size(); ++row)
                for (col = 0; col != row; ++col)
                    swap(box[col][row], box[row][col]);
            return box;
        }

        vector<vector<char>> result(box.front().size(),
                                    vector<char>(box.size()));
        for (row = 0ul; row != box.size(); ++row)
            for (col = 0; col != box.front().size(); ++col)
                result[col][rowsMinus1 - row] = box[row][col];
        return result;
    }
};

int main () {
    
    return 0;
}
