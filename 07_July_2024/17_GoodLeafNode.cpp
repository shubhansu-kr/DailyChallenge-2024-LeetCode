// https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/description/?envType=daily-question&envId=2024-07-18

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
int countGoodNodes;
    
     unordered_map<int, int> dfs(TreeNode* node, int dis) {
        if(node == nullptr) return {};
        unordered_map<int, int> mp; mp[1] = 1;
        if(node->left == nullptr && node->right == nullptr) return mp;

        unordered_map<int, int> leftv = dfs(node->left, dis);
        unordered_map<int, int> rightv = dfs(node->right, dis);

        for(auto &[lv, lf] : leftv) {
            for(auto &[rv, rf] : rightv) {
                if(lv + rv <= dis) countGoodNodes += (rf * lf);
            }
        }

        unordered_map<int, int> parentNodes;

        for(auto &[lv,lf] : leftv) {
            if(lv+1 < dis) {
                   parentNodes[lv+1] += lf;
            }
            
        }
        for(auto &[rv,rf] : rightv) {
            if(rv+1 < dis) {
                   parentNodes[rv+1] += rf;
            }
        }

        return parentNodes;
     }
    int countPairs(TreeNode* root, int dis) {
        countGoodNodes = 0;
        dfs(root, dis);
        return countGoodNodes;
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