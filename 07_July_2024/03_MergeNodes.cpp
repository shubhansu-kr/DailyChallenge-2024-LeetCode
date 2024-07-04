// https://leetcode.com/problems/merge-nodes-in-between-zeros/?envType=daily-question&envId=2024-07-04

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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *p = head, *q = head->next, *prev = nullptr;
        int sum = 0;
        while(q) {
            if (q->val){
                sum += q->val;
            }
            else {
                p->val = sum;
                sum = 0;
                p->next = q;
                prev = p;
                p = q;
            }
            q = q->next;
        }
        prev->next = nullptr;
        return head;
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