// https://leetcode.com/problems/split-linked-list-in-parts/?envType=daily-question&envId=2024-09-08

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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode *> res(k, nullptr);
        ListNode *p = head;
        int count = 0, l, f;
        while (p != NULL)
        {
            p = p->next;
            count++;
        }

        if (count == 0)
        {
            return res;
        }

        if (k >= count)
        {
            l = 2;
            f = 0;
        }
        else
        {
            l = count / k + 1;
            f = count % k;
        }

        for (int i = 0; i < k; i++)
        {
            if (head == NULL)
            {
                break;
            }
            if (f == 0)
            {
                l--;
            }
            ListNode *temp = head;
            ListNode *prev;
            for (int j = 0; j < l; j++)
            {
                if (j == l - 1)
                {
                    prev = temp;
                }
                temp = temp->next;
            }
            prev->next = NULL;
            res[i] = head;
            head = temp;
            f--;
        }
        return res;
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