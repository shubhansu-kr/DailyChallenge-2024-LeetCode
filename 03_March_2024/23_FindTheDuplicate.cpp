// https://leetcode.com/problems/find-the-duplicate-number/?envType=daily-question&envId=2024-03-24

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[slow];
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        slow = nums[0];
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

int main () {
    int n = 0;
    int x = 0;
    while(n < 129) {
        x ^= n;
        cout << n << " : " << x << endl;
        ++n;
    }
    return 0;
}