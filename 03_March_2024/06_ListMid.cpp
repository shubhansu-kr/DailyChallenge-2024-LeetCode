// https://leetcode.com/problems/middle-of-the-linked-list/?envType=daily-question&envId=2024-03-07

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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL){
            fast = fast->next;
            slow = slow->next;
            if(fast->next!=NULL){
                fast = fast->next; 
            }
        }
        return slow;
    }
};

int main () {
    
    return 0;
}