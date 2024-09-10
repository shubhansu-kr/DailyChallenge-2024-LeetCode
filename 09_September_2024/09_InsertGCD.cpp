// https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/?envType=daily-question&envId=2024-09-10

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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* curr=head;
        ListNode* prev=head;
        ListNode* next=head->next;
        while(next!=NULL){
            int gcd=__gcd(prev->val,next->val);
            ListNode* newNode=new ListNode(gcd);
            curr->next=newNode;
            newNode->next=next;   
            prev=next;
            curr=prev;
            next=next->next;
        }
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