// https://leetcode.com/problems/reverse-linked-list/?envType=daily-question&envId=2024-03-21

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
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *p = head;
        while(p){
            ListNode *temp = p->next;
            p->next = prev;
            prev = p;
            p = temp;
        }
        return prev;
    }
};

int main () {
    
    return 0;
}