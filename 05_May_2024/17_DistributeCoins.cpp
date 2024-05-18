// https://leetcode.com/problems/distribute-coins-in-binary-tree/?envType=daily-question&envId=2024-05-18

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
    int res = 0;
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return res;
    }
    int dfs(TreeNode* root) {
        if (!root) return 0;
        int left = dfs(root->left), right = dfs(root->right);
        res += abs(left) + abs(right);
        return root->val + left + right - 1;
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