// https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/?envType=daily-question&envId=2024-06-13

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end()) ;
        sort(students.begin(), students.end()) ;
        int minMoves = 0 ;
        for (size_t i = 0; i < seats.size(); i++)
        {   
            if (seats[i] >= students[i]) {
                minMoves += (seats[i] - students[i]) ;
            }
            else {
                minMoves += (students[i]-seats[i]) ;
            }
        }
        return minMoves ;
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