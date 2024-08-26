// https://leetcode.com/problems/n-ary-tree-postorder-traversal/?envType=daily-question&envId=2024-08-26

#include <bits/stdc++.h>
using namespace std ;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    void solve(Node* root, vector<int> &ans) {
        if (!root) return;

        for(auto &it: root->children){
            solve(it, ans);
        }

        ans.emplace_back(root->val);
    }
    vector<int> postorder(Node* root) {
        vector<int> ans;
        solve(root, ans);
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