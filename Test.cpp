// Mock Test - Amazon

#include <bits/stdc++.h>
using namespace std ;

int findMaxZeroes(vector<int> arr) {
    int n = arr.size();
    vector<int> leftMin(n);

    int mini = INT_MAX;
    for(int i = 0; i < n; ++i) {
        mini = min(arr[i], mini);
        leftMin[i] = mini;
    }

    int count = 0; 
    for(int i = 0; i < n; ++i) {
        count += (arr[i] == leftMin[i]);
    }
    return count;
}
int getOutlierValue(vector<int> arr) {

    map<int, int> mp;
    int sum = 0;
    int sol = 0;

    for(int i=0; i<arr.size(); i++){
        sum += arr[i];
        mp[arr[i]]++;
    }

    for(int i=0; i<arr.size(); i++)
    {
        if(mp.find((sum-arr[i])/2)!=mp.end() && arr[i]!=(sum-arr[i])/2 && (sum-arr[i])%2==0) sol = max(sol, arr[i]);   
    }
    
    return sol;
}

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

int main () {
    
    vector<int> arr = {4,1,2,1, 10, 3};
    cout << getOutlierValue(arr);
    return 0;
}