// Mock Test - Amazon

#include <bits/stdc++.h>
using namespace std ;

long getMinValue(vector<long> power, long armor) {
    long minHealthRequired = 1; 
    long maxHealth = INT_MIN;

    for(auto &it: power) {
        maxHealth = max(maxHealth, it);
        minHealthRequired += it;
    }

    minHealthRequired -= min(armor, maxHealth);
    
    return minHealthRequired;
}

int findLongestLength(const string& fullString) {
    int n = fullString.size();
    if (n <= 1) return 0;

    unordered_map<char, int> totalFrequency;
    for (char c : fullString) {
        totalFrequency[c]++;
    }

    int maxLength = 0;

    for (int i = 0; i < n; ++i) {
        unordered_map<char, int> substringFrequency;
        unordered_set<char> uniqueChars;
        bool isSelfSufficient = true;

        for (int j = i; j < n; ++j) {
            char currentChar = fullString[j];
            substringFrequency[currentChar]++;
            uniqueChars.insert(currentChar);

            for (char c : uniqueChars) {
                if (substringFrequency[c] > 0 && totalFrequency[c] != substringFrequency[c]) {
                    isSelfSufficient = false;
                    break;
                }
            }

            if (isSelfSufficient && (j - i + 1 < n)) {
                maxLength = max(maxLength, j - i + 1);
            } else {
                break;
            }
        }
    }

    return maxLength;
}

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

int maxSubstringLength(string s) {
        vector<int> first(26, -1);
        vector<int> last(26);
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            int j = s[i] - 'a';
            if (first[j] == -1) {
                first[j] = i;
            }
            last[j] = i;
        }
        int ans = -1;
        for (int k = 0; k < 26; ++k) {
            int i = first[k];
            if (i == -1) {
                continue;
            }
            int mx = last[k];
            for (int j = i; j < n; ++j) {
                int a = first[s[j] - 'a'];
                int b = last[s[j] - 'a'];
                if (a < i) {
                    break;
                }
                mx = max(mx, b);
                if (mx == j && j - i + 1 < n) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        if (ans == -1) ans = 0;
        return ans;
    }

int main () {
    
    vector<long> arr = {1, 2, 3};
    // cout << getOutlierValue(arr);
    
    string input = "amazonservices";
    
    // cout << getMinValue(arr, 1);
    cout << maxSubstringLength(input);

    return 0;
}