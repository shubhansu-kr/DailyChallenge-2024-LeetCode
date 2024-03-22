// https://leetcode.com/problems/palindrome-linked-list/?envType=daily-question&envId=2024-03-22

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
    // WA: r pointer is not being updated in backtracking
public:
    bool solve(ListNode *l, ListNode*r) {
        if (!l) return true;
        if(!solve(l->next, r)) return false;
        cout << l->val << " " << r->val << endl;
        if(l->val != r->val) return false;
        r = r->next;
        return true;
    }

    bool isPalindrome(ListNode* head) {
        return solve(head, head);
    }
};

int main () {
    
    return 0;
}