// https://leetcode.com/problems/smallest-string-starting-from-leaf/?envType=daily-question&envId=2024-04-17

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
    string smallestFromLeaf(TreeNode* r, string s = "") {
    s = string(1, 'a' + r->val) + s;
    return r->left == r->right ? s : min(r->left ? smallestFromLeaf(r->left, s) : "|", 
        r->right ? smallestFromLeaf(r->right, s) : "|");
}
};

class Solution {
    // Wrong Answer
public:
    string smallestFromLeaf(TreeNode* root) {
        if (!root) return "";

        char v = 'a' + root->val;
        string curr = "";
        curr += v;

        string l = "", r = "";
        if (root->left) l = smallestFromLeaf(root->left);
        if (root->right) r = smallestFromLeaf(root->right);

        if (l != "" && r != "") {
            if (l < r) return l + curr;
            else return r + curr;
        }
        if (l != "") return l + curr;
        if (r != "") return r + curr;
        return curr;
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