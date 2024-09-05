// https://leetcode.com/problems/find-missing-observations/?envType=daily-question&envId=2024-09-05

#include <bits/stdc++.h>
using namespace std ;

class Solution {
private:
    vector<int> createArray(int n, int s) {
    vector<int> arr(n, 1);

    int remaining = s - n;

    if (remaining < 0 || s > 6 * n) {
        cout << "Not possible to create an array with sum " << s << " and size " << n << endl;
        return {};
    }

    for (int i = 0; i < n && remaining > 0; i++) {
        int increment = min(5, remaining); 
        arr[i] += increment;
        remaining -= increment;
    }

    return arr;
}

public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {

        vector<int>ans;
        
        int avg = 0;
        int sumofM = 0;
        for(int i=0; i<rolls.size(); i++)
        sumofM += rolls[i];

        int totalSum = mean*(n + rolls.size());
        int sumofN = totalSum - sumofM;

        ans = createArray(n, sumofN);

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