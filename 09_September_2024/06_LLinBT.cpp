// https://leetcode.com/problems/linked-list-in-binary-tree/?envType=daily-question&envId=2024-09-07

#include <bits/stdc++.h>
using namespace std ;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct ListNode {
    int val;
    ListNode * next;
    ListNode():val(0), next(nullptr){}
    ListNode(int val):val(val), next(nullptr){}
    ListNode(int val, ListNode *next):val(val), next(next){}
};

class Solution {
public:
    bool verify(ListNode *head, TreeNode*root) {
        if (!head) return true;
        if (!root) return false;
        
        if (head->val != root->val) return false;

        if (verify(head->next, root->left)) return true;

        return verify(head->next, root->right);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false;

        if (root->val == head->val) {
            if (verify(head, root)) return true;
        }
        
        bool left = isSubPath(head, root->left);
        if (left) return true;

        bool right = isSubPath(head, root->right);

        return left || right;
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