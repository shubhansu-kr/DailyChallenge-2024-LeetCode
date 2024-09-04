// https://leetcode.com/problems/walking-robot-simulation/?envType=daily-question&envId=2024-09-04

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int robotSim(vector<int>& c, vector<vector<int>>& o) {
        int i = 0, j = 0, x = 0, y = 0, f = 0, t = 0, k = 0, a = -1, m = 0, max = 0;
        int ar = 0;
        sort(o.begin(), o.end());
        for( i = 0; i < c.size(); i++ ) {
            if( c[i] == -1 ) {
                t++;
                continue;
            }
            else if( c[i] == -2 ) {
                t--;
                continue;
            }
            else {
                for( j = 0; j < c[i]; j++ ) {
                    
                    if( f == 1 ) {
                        break;
                    }
                    else {
                        int p = t;
                        while( p < 0 ) {
                            p += 4;
                        }
                        p = p % 4;
                        if( p == 0 ) {
                            a = 0;
                            y++;
                        }
                        else if( p == 1 ) {
                            a = 1;
                            x++;
                        }
                        else if( p == 2 ) {
                            a = 2;
                            y--;
                        }
                        else if( p == 3 ) {
                            a = 3;
                            x--;
                        }
                    }
                    vector<int> pos = {x, y};
                if(binary_search(o.begin(), o.end(),pos)) {
                    f = 1;
                    // Revert the move
                    if( a == 0 ) y--;
                    else if( a == 1 ) x--;
                    else if( a == 2 ) y++;
                    else if( a == 3 ) x++;
                    break;
                }

                    ar = ( ( y * y ) + ( x * x ) );
                    
                    if( ar > max ) {
                        max = ar;
                    }
                    
                }
                
                
            }
            
            if( f == 1 ) {
                f = 0;
                continue;
            }
        }
        
        return max;
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