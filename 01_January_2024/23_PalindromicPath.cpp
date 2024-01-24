// https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/?envType=daily-question&envId=2024-01-24

#include <bits/stdc++.h>
using namespace std ;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root, int count = 0) {
         if (!root) return 0;
        count ^= 1 << (root->val - 1);
        int res = pseudoPalindromicPaths(root->left, count) + pseudoPalindromicPaths(root->right, count);
        if (root->left == root->right && (count & (count - 1)) == 0) res++;
        return res;         
    }
    int solve(TreeNode *root, unordered_set<int> &freq) {
        if (!root) {return freq.size() < 2;}
        if(freq.count(root->val)) freq.erase(root->val);
        else freq.insert(root->val);
        int left = solve(root->left, freq);
        int right = 0; 
        if (root->left || root->right) right = solve(root->right, freq);
        return left + right;
    }
};

int main () {
    
    return 0;
}