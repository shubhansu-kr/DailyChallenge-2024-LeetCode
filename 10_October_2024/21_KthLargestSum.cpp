// https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/?envType=daily-question&envId=2024-10-22

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

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long>levelsum;
        queue<TreeNode*>q;
        if(root==nullptr) return -1;
        q.push(root);
        while(!q.empty()){
            long long currsum=0;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode*curr=q.front();
                q.pop();
                currsum+=(long long)curr->val;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            levelsum.push(currsum);
        }
        if(levelsum.size()<k) return -1;
        while(k>1){
            k--;
            levelsum.pop();
        }
        return levelsum.top();
    }
};

int main () {
    
    return 0;
}
