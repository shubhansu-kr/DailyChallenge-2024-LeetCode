// https://leetcode.com/problems/diameter-of-binary-tree/?envType=daily-question&envId=2024-02-27

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
    int diameterOfBinaryTree(TreeNode* root) {
        findDia(root);
        return maxDia;
    }
private:
    int maxDia = 0;
    int findDia(TreeNode* root){
        if(root == NULL)return 0;
        int leftDepth = findDia(root->left);
        int rightDepth = findDia(root->right);
        int currDia = leftDepth + rightDepth;
        maxDia = max(maxDia, currDia);
        return 1 + max(leftDepth, rightDepth);
    }
};

class Solution {
    // WA
public:
    void solve(TreeNode *root, int index, int &mini, int &maxi) {
        if (!root) return;

        mini = min(index, mini);
        maxi = max(index, maxi);

        solve(root->left, index-1, mini, maxi);
        solve(root->right, index+1, mini, maxi);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int mini = 0, maxi = 0;
        solve(root, 0, mini, maxi);
        return (maxi-mini);
    }
};

int main () {
    
    return 0;
}