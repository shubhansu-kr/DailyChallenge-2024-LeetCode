// https://leetcode.com/problems/flip-equivalent-binary-trees/?envType=daily-question&envId=2024-10-24

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
    bool flip(TreeNode*& root1 , TreeNode*& root2){
       if(root1==NULL && root2!=NULL){
          return false;
       }
       else if(root2==NULL && root1!=NULL){
          return false;
       }
       else if(root1==NULL && root2==NULL){
          return true;
       }
       else if(root1->val != root2->val){
          return false;
       }
       bool ans1 = flip(root1->right,root2->right) && flip(root1->left,root2->left);
       if(ans1){
        return 1;
       }
       bool ans2 = flip(root1->left,root2->right) && flip(root1->right,root2->left);
       if(ans2){
        return  1;
       }
       return 0;
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
       return flip(root1,root2);
    }
};

int main () {
    
    return 0;
}
