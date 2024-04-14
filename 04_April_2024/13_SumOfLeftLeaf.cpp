// https://leetcode.com/problems/sum-of-left-leaves/?envType=daily-question&envId=2024-04-14

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
    int solve(TreeNode *root, bool key) {
        if (!root) return 0;

        if (!root->left && !root->right && key){
            return root->val;
        }

        return solve(root->left, true) + solve(root->right, false);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return;
        return solve(root, false);
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