// https://leetcode.com/problems/merge-in-between-linked-lists/?envType=daily-question&envId=2024-03-20

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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *p = list2;
        while(p->next) {
            p = p->next;
        }
        ListNode *x = nullptr, *y = nullptr;
        ListNode *q = list1;
        while(q){
            if (b == 0) y = q->next;
            if (a == 0 && b == 0) break;
            a--;
            if (a == 0) x = q;
            b--;
            q = q->next;
        }
        x->next = list2, p->next = y;
        return list1;
    }
};

int main () {
    
    return 0;
}