// https://leetcode.com/problems/find-bottom-left-tree-value/?envType=daily-question&envId=2024-02-28

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
    void solve(TreeNode *root, int &maxHeight, int &ans, int h) {
        if (!root) return;

        if (h > maxHeight) {
            ans = root->val;
            maxHeight = h;
        }
        solve(root->left, maxHeight, ans, h+1);
        solve(root->right, maxHeight, ans, h+1);

        return;
    }
    int findBottomLeftValue(TreeNode* root) {
        int ans = -1, maxHeight = -1;
        solve(root, maxHeight, ans, 0);
        return ans;
    }
};

int main () {
    
    return 0;
}