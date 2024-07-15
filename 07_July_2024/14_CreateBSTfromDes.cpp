// https://leetcode.com/problems/create-binary-tree-from-descriptions/?envType=daily-question&envId=2024-07-15

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
    // BruteForce
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_set<int> st, ct;
        unordered_map<int, TreeNode *> mp;
        
        TreeNode *head = nullptr;

        for(auto &it: descriptions) {
            int parent = it[0], child = it[1], isLeft = it[2];

            ct.insert(child);

            TreeNode *q = nullptr;
            if (st.count(child)) {
                q = mp[child];
            }
            else {
                q = new TreeNode(child);
                st.insert(child);
                mp[child] = q;
            }


            TreeNode *p = nullptr;
            if (st.count(parent)) {
                p = mp[parent];
            }
            else {
                p = new TreeNode(parent);
                st.insert(parent);
                mp[parent] = p;
            }

            if (isLeft) {
                p->left = q;
            }
            else {
                p->right = q;
            }            
        }
        for(auto &it: mp) {
            if (!ct.count(it.first)) {
                return it.second;
            }
        }
        return head;
    }
};


class Solution {
    // BruteForce
    // Wrong answer : [[85,82,1],[74,85,1],[39,70,0],[82,38,1],[74,39,0],[39,13,1]]
    // Reason : Ct.insert Is in wrong position
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_set<int> st, ct;
        unordered_map<int, TreeNode *> mp;
        
        TreeNode *head = nullptr;

        for(auto &it: descriptions) {
            int parent = it[0], child = it[1], isLeft = it[2];

            TreeNode *q = nullptr;
            if (st.count(child)) {
                q = mp[child];
            }
            else {
                q = new TreeNode(child);
                st.insert(child);
                mp[child] = q;
                ct.insert(child);
            }


            TreeNode *p = nullptr;
            if (st.count(parent)) {
                p = mp[parent];
            }
            else {
                p = new TreeNode(parent);
                st.insert(parent);
                mp[parent] = p;
            }

            if (isLeft) {
                p->left = q;
            }
            else {
                p->right = q;
            }            
        }

        for(auto &it: mp) {
            if (!ct.count(it.first)) return it.second;
        }
        return head;
    }
};


class Solution {
    // BruteForce
    // Wrong Answer : [[85,82,1],[74,85,1],[39,70,0],[82,38,1],[74,39,0],[39,13,1]]
    // Reason : Head is not placed properly. 
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_set<int> st;
        unordered_map<int, TreeNode *> mp;
        
        TreeNode *head = nullptr;

        for(auto &it: descriptions) {
            int parent = it[0], child = it[1], isLeft = it[2];

            TreeNode *q = nullptr;
            if (st.count(child)) {
                q = mp[child];
            }
            else {
                q = new TreeNode(child);
                st.insert(child);
                mp[child] = q;
            }


            TreeNode *p = nullptr;
            if (st.count(parent)) {
                p = mp[parent];
            }
            else {
                p = new TreeNode(parent);
                st.insert(parent);
                mp[parent] = p;

                head = p;
            }

            if (isLeft) {
                p->left = q;
            }
            else {
                p->right = q;
            }            
        }

        return head;
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