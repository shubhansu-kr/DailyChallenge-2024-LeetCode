// https://leetcode.com/problems/cousins-in-binary-tree-ii/description/?envType=daily-question&envId=2024-10-23

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root == NULL){
            return root;
        }

        queue<TreeNode*> q;
        q.push(root);
        vector<int> levelSum;

        while(!q.empty()){
            int currLevelSum = 0;
            int n = q.size();
            
            while(n--){
                TreeNode* curr = q.front();
                q.pop();
                currLevelSum += curr -> val;
                if(curr -> left)
                    q.push(curr -> left);
                if(curr -> right)
                    q.push(curr -> right);
            }
            levelSum.push_back(currLevelSum);
        }

        q.push(root);
        root -> val = 0;
        int i = 1;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                TreeNode* curr = q.front();
                q.pop();

                int siblingSum = curr -> left != NULL? curr -> left -> val : 0;
                siblingSum += curr -> right != NULL? curr -> right -> val : 0;

                if(curr -> left){
                    curr -> left -> val = levelSum[i] - siblingSum;
                    q.push(curr ->left);
                }
                if(curr -> right){
                    curr -> right -> val = levelSum[i] - siblingSum;
                    q.push(curr -> right);
                }
            }
            i++;
        }
        return root;
    }
};

int main () {
    
    return 0;
}
