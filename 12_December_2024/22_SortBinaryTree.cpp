// https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/?envType=daily-question&envId=2024-12-23

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

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
    int helper(vector<int>& v){
        int cnt = 0;
        map<int, int> mp;
        vector<int> copy(v.begin(), v.end());

        for(int i=0; i<v.size(); i++){
            mp[v[i]] = i;
        }

        sort(copy.begin(), copy.end());
        for(int i=0; i<v.size(); i++){
            if(v[i] != copy[i]){
                v[mp[copy[i]]] = v[i];
                mp[v[i]] = mp[copy[i]];
                mp[copy[i]] = i;
                v[i] = copy[i];
                cnt++;
            }
        }

        return cnt;
    }

    int minimumOperations(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> v;
            while(n--){
                TreeNode* node = q.front();
                q.pop();

                v.push_back(node->val);
                if(node->left != NULL){
                    q.push(node->left);
                }
                if(node->right != NULL){
                    q.push(node->right);
                }
            }

            ans += helper(v);

        }

        return ans;
    }
};

int main () {
    
    return 0;
}
