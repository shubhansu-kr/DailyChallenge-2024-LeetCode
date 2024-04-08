// https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/?envType=daily-question&envId=2024-04-08

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int req1 = 0, avl1 = 0;
        int n = students.size();
        for(int i = 0; i < n; ++i) {
            if (students[i]) req1++;
            if (sandwiches[i]) avl1++;
        }
        cout << req1 << endl;
        cout << avl1 << endl;
        int target = 0, count = 0;
        if (req1 == avl1) return 0;
        else if (req1 > avl1) {
            target = 0;
            count = n-req1;
        }
        else {
            target = 1;
            count = req1;
        }
        cout << target << endl;
        cout << count << endl;
        for(int i = 0; i < n; ++i) {
            if (count == 0 && sandwiches[i] == target) {
                return n-i;
            }
            if (sandwiches[i] == target) --count;
        }

        return -1;
    }
};

class Solution {
    // Wrong Answer: 
    // TestCase: sand = [1,0,0,0,0,0,0,1,0,0,1,0,1,1,1,0] stud = [0,0,1,1,0,0,0,0,1,0,0,1,1,0,1,1]
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int req1 = 0, avl1 = 0;
        int n = students.size();
        for(int i = 0; i < n; ++i) {
            if (students[i]) req1++;
            if (sandwiches[i]) avl1++;
        }
        int target = 0, count = 0;
        if (req1 == avl1) return 0;
        else if (req1 > avl1) {
            target = 0;
            count = n-req1;
        }
        else {
            target = 1;
            count = req1;
        }

        for(int i = 0; i < n; ++i) {
            if (count == 0) {
                return n-i;
            }
            if (sandwiches[i] == target) --count;
        }

        return -1;
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