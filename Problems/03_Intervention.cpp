// 

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

int getStableSeconds() {
    int N;
    cin >> N;

    vector<int> array(N);
    if (N <= 0 ) return 0;
    for(int i = 0; i < N; ++i) {
        cin >> array[i];
    }

    int maxSeconds = -1, currentSeconds = 0;
    int currentElement = -1;
    for(int i = N-1; i >= 0; --i) {
        if (array[i] >= currentElement) {
            currentElement = array[i];
            maxSeconds = max(maxSeconds, currentSeconds);
            currentSeconds = 0;
        }
        else {
            ++currentSeconds;
        }
    }
    maxSeconds = max(maxSeconds, currentSeconds);
    return maxSeconds;
}

int main () {
    
    int T;
    cin >> T;

    while (T--) {
        cout << getStableSeconds() << endl;
    }
    return 0;
}
