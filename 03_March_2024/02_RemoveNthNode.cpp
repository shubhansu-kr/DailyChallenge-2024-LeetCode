// https://leetcode.com/problems/remove-nth-node-from-end-of-list/?envType=daily-question&envId=2024-03-03

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head, *prev = nullptr, *q = head;
        while(p) {
            if (n) {
                p = p->next;
                --n;
            }
            else {
                prev = q;
                q = q->next;
                p = p->next;
            }
        }
        if (prev) prev->next = q->next;
        else head = head->next;
        return head;
    }
};

int main () {
    
    return 0;
}