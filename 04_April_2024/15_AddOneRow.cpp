// https://leetcode.com/problems/add-one-row-to-tree/?envType=daily-question&envId=2024-04-16

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
    void add(TreeNode *root, int &val, int &depth, int i){
        if (!root) return;

        if (i == depth-1) {
            
            TreeNode *l = new TreeNode(val);
            l->left = root->left;
            root->left = l;
            
            
            TreeNode *r = new TreeNode(val);
            r->right = root->right;
            root->right = r;
            
        }
        else {
            add(root->right, val, depth, i+1);
            add(root->left, val, depth, i+1);
        }    
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode *p = new TreeNode(val);
            p->left = root;
            return p;
        }

        add(root, val, depth, 1);
        return root;
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