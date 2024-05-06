// https://leetcode.com/problems/remove-nodes-from-linked-list/?envType=daily-question&envId=2024-05-06

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
    ListNode* removeNodes(ListNode* head) {
        ListNode tmp(INT_MAX);
        vector<ListNode*> st{ &tmp };
        for (auto p = head; p != nullptr; p = p->next) {
            while (st.back()->val < p->val) 
                st.pop_back();
            st.back()->next = p;
            st.push_back(p);
        }
        return tmp.next;
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