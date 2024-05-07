// https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/?envType=daily-question&envId=2024-05-07

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
    ListNode* reverseList(ListNode* cur, ListNode* prev = nullptr) {
        while (cur != nullptr) {
            swap(cur->next, prev);
            swap(prev, cur);     
        }
        return prev;    
    }
    ListNode* doubleIt(ListNode* head) {
        head = reverseList(head);
        int carry = 0;
        for (auto p = head; p != nullptr; p = p->next) {
            int val = p->val * 2 + carry;
            p->val = val % 10;
            carry = val / 10;
        }
        return carry ? new ListNode(carry, reverseList(head)) : reverseList(head);
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