// https://leetcode.com/problems/same-tree/?envType=daily-question&envId=2024-02-26

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

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p) return false;
        if (!q) return false;

        if (p->val != q->val) return false;

        // Check left subtree & right subtree
        if (isSameTree(p->left, q->left)) return isSameTree(p->right, q->right);

        return false;
    }
};

int main () {
    
    return 0;
}