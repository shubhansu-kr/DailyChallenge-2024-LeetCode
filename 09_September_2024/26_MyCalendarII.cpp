// https://leetcode.com/problems/my-calendar-ii/?envType=daily-question&envId=2024-09-27

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class MyCalendarTwo {
private:
    map<int, int> count; 
    int maxOverLapping;
public:
    MyCalendarTwo() {
        maxOverLapping = 2;
    }
    
    bool book(int start, int end) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        count[start]++;
        count[end]--;

        int overLapped = 0;

        for(pair<int, int> bookings: count){
            overLapped += bookings.second;

            if(overLapped > maxOverLapping){

                count[start]--;
                count[end]++;

                
                if(count[start] == 0){
                    count.erase(start);
                }

                if(count[end] == 0){
                    count.erase(end);
                }

                return false;
            }
        }

        return true;
    }  
};

int main () {
    
    return 0;
}
