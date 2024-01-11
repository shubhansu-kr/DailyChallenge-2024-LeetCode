// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/?envType=daily-question&envId=2024-01-11

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int maxAncestorDiff(TreeNode* root, int mn = 100000, int mx = 0) {
        return root ? max(maxAncestorDiff(root->left, min(mn, root->val), max(mx, root->val)),
        maxAncestorDiff(root->right, min(mn, root->val), max(mx, root->val))) : mx - mn;
    }
};

int main () {
    
    return 0;
}