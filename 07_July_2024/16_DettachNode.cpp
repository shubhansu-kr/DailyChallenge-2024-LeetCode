// https://leetcode.com/problems/delete-nodes-and-return-forest/?envType=daily-question&envId=2024-07-17q

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
    void traverse(TreeNode *root, vector<TreeNode*> &ans, unordered_set<int> st){
        if (!root) return;

        traverse(root->left, ans, st);
        traverse(root->right, ans, st);

        if (root->left && st.count(root->left->val)) {
            root->left = nullptr;
        }
        if (root->right && st.count(root->right->val)) {
            root->right = nullptr;
        }

        if (st.count(root->val)) {
            if (root->left) {
                ans.emplace_back(root->left);
            }
            if (root->right) {
                ans.emplace_back(root->right);
            }
        }
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> st(to_delete.begin(), to_delete.end());
        vector<TreeNode *> ans;

        traverse(root, ans, st);

        if (root && !st.count(root->val)){
            ans.emplace_back(root);
        }
        return ans;
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