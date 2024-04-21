

#include <bits/stdc++.h>
using namespace std ;



auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

int findDup(string &s) {
    int count = 0;
    unordered_set<char> st;
    for(auto &it: s) {
        if (st.count(it)) {
            ++count;
        }
        st.insert(it);
    }
    return count;
}
int main () {
    int t; 
    cin >> t;

    while(t--){
        string s;
        cin >> s;

        cout << findDup(s) << endl;
    }
    return 0;
}