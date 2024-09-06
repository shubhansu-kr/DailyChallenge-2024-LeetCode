// https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/?envType=daily-question&envId=2024-09-06

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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode *p = head, prev = nullptr;
        unordered_set<int> st(nums.begin(), nums.end());

        while(p) {
            if (st.count(p->val)){
                if (prev) {
                    p = p->next;
                    prev->next = p;
                }
                else {
                    head = head->next;
                    p = head;
                }
            }
            else {
                prev = p;
                p = p->next;
            }
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