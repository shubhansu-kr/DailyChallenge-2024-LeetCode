// This is a C++ program that finds the length of the
// longest subarray in an array such that the sum of its
// elements is at most k.

#include <bits/stdc++.h>
using namespace std;

int numberOfAlerts (int precedingMinutes, int alertThreshold, vector<int> numCalls) {
    int count = 0;
    float sum = 0, avg = 0;
    int n = numCalls.size();
    for(int i = 0; i < n; ++i) {
        if (i < precedingMinutes-1) {
            sum += numCalls[i];
        }
        else if (i == precedingMinutes - 1){
            sum += numCalls[i];
            avg = sum/precedingMinutes;
            if (avg > alertThreshold) ++count; 
        }
        else {
            sum += (numCalls[i] - numCalls[i-precedingMinutes]);
            avg = sum/precedingMinutes;
            if (avg > alertThreshold) ++count;
        }
    }
    if (precedingMinutes > n) {
        avg = sum/precedingMinutes;
        if (avg > alertThreshold) ++count;
    }
    return count;
}



// Function to find the length of the largest subarray
// having a sum at most k.
int atMostSum(int a[], int n, int k)
{
    int sum = 0;
    int cnt = 0;
    int maxcnt = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] > k) {
            sum=0;
            cnt = 0;
            continue;
        }

        if ((sum + a[i]) <= k) {
            cnt++;
            sum += a[i];
        }
        else {
            cnt++;
            sum += a[i];
            while (sum > k) {
                sum -= a[i - cnt + 1];
                cnt--;
            }
        }
        maxcnt = max(cnt, maxcnt);
    }
    return maxcnt;
}

int main()
{
    int a[] = { 0, 10, 11, 10, 10};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 4;

    vector<int> arr = {0, 10, 11, 10, 7};

    cout << numberOfAlerts(3, 10, arr);
    return 0;
}