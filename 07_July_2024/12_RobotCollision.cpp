// https://leetcode.com/problems/robot-collisions/?envType=daily-question&envId=2024-07-13

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
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<tuple<int, int, char, int>> robots; 
        
        for (int i = 0; i < n; ++i) {
            robots.emplace_back(positions[i], healths[i], directions[i], i);
        }
        
        sort(robots.begin(), robots.end());
        
        stack<tuple<int, int, char, int>> stk;
        vector<int> result(n, -1);

        for (const auto& robot : robots) {
            int pos = get<0>(robot);
            int health = get<1>(robot);
            char dir = get<2>(robot);
            int index = get<3>(robot);
            
            if (dir == 'R') {
                stk.push(robot); 
            } else {
                while (!stk.empty() && get<2>(stk.top()) == 'R' && health > 0) {
                    auto rightRobot = stk.top();
                    int rightHealth = get<1>(rightRobot);
                    
                    if (rightHealth < health) {
                        stk.pop();
                        health--;
                    } else if (rightHealth > health) {
                        get<1>(stk.top())--;
                        health = 0;
                    } else {
                        stk.pop();
                        health = 0;
                    }
                }
                
                if (health > 0) {
                    result[index] = health;
                }
            }
        }
        
        while (!stk.empty()) {
            auto robot = stk.top();
            stk.pop();
            result[get<3>(robot)] = get<1>(robot);
        }
        
        vector<int> survivors;
        for (int h : result) {
            if (h != -1) survivors.push_back(h);
        }
        
        return survivors;
    }
};


int main () {
    
    return 0;
}