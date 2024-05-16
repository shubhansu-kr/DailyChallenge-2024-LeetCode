// https://leetcode.com/problems/evaluate-boolean-binary-tree/?envType=daily-question&envId=2024-05-16

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
    bool evaluateTree(TreeNode* root) {
        if(root->left == nullptr && root->right == nullptr){
            if(root->val == 0) return false;
            return true;
        }
        bool left = evaluateTree(root->left);
        bool right = evaluateTree(root->right);
        if(root->val == 2) return left || right;
        return left && right;
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