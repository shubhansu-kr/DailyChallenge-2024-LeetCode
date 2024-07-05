// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/?envType=daily-question&envId=2024-07-05

#include <bits/stdc++.h>
using namespace std ;

struct ListNode {
    int val;
    ListNode * next;
    ListNode():val(0), next(nullptr){}
    ListNode(int val):val(val), next(nullptr){}
    ListNode(int val, ListNode *next):val(val), next(next){}
};

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> res(2, 100000);
        ListNode *prev = head;
        head = head->next;
        int curr = 0;
        int max = 0;
        int flag = 0;
        while (head->next)
        {
            if (flag)
            {
                curr++;
                max++;
            }
            if (head->val < prev->val && head->val < head->next->val)
            {
                // Critical Point - Minima
                if (res[0] > curr && flag)
                {
                    res[0] = curr;
                }
                flag = 1;
                curr = 0;
            }
            else if (head->val > prev->val && head->val > head->next->val)
            {
                // Critical Point - Maxima
                if (res[0] > curr && flag)
                {
                    res[0] = curr;
                }
                flag = 1;
                curr = 0;
            }
            prev = head;
            head = head->next;
        }
        if (max - curr == 0)
        {
            res[0] = res[1] = -1;
            return res;
        }
        res[1] = max - curr;
        return res;
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