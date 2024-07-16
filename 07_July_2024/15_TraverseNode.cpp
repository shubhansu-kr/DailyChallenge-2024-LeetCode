// https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/?envType=daily-question&envId=2024-07-16

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

/* 
Traverse Function: 

Input: [5,1,2,3,null,6,4]

CurrentNode: 5
currentPath: 5, 
currentMove: 
moveToSource: 
moveToDest: 
PathToSource: 0
PathToDest: 0


CurrentNode: 1
currentPath: 5, 1, 
currentMove: L
moveToSource: 
moveToDest: 
PathToSource: 0
PathToDest: 0


CurrentNode: 3
currentPath: 5, 1, 3, 
currentMove: LL
moveToSource: 
moveToDest: 
PathToSource: 0
PathToDest: 0


CurrentNode: 2
currentPath: 5, 2, 
currentMove: R
moveToSource: LL
moveToDest: 
PathToSource: 3
PathToDest: 0


CurrentNode: 6
currentPath: 5, 2, 6, 
currentMove: RL
moveToSource: LL
moveToDest: 
PathToSource: 3
PathToDest: 0


CurrentNode: 4
currentPath: 5, 2, 4, 
currentMove: RR
moveToSource: LL
moveToDest: RL
PathToSource: 3
PathToDest: 3

*/

class Solution {
    // BruteForce: Use Lowest Common ancestor
public:

    // void print(vector<int> &pathToSource, vector<int> &pathToDest, vector<int> &currPath, string &moveToSource, string &moveToDest, string &currMove, int &curr) {
    //     cout << "CurrentNode: " << curr << endl;
    //     cout << "currentPath: ";
    //     for(auto &it: currPath) {
    //         cout << it << ", ";
    //     }
    //     cout << "\ncurrentMove: " << currMove << endl;
    //     cout << "moveToSource: " << moveToSource << endl;
    //     cout << "moveToDest: " << moveToDest << endl;
    //     cout << "PathToSource: " << pathToSource.size() << endl;
    //     cout << "PathToDest: " << pathToDest.size() << endl;
    //     cout << endl << endl;
    // }

    void traverse(TreeNode *root, vector<int> &pathToSource, vector<int> &pathToDest, vector<int> &currPath, string &moveToSource, string &moveToDest, string &currMove, int &source, int &dest){
        if (!root) return;

        int curr = root->val;
        currPath.push_back(curr);

        // print(root->left, pathToSource, pathToDest, currPath, moveToSource, moveToDest, currMove, curr);
        
        currMove.push_back('L');
        traverse(root->left, pathToSource, pathToDest, currPath, moveToSource, moveToDest, currMove, source, dest);
        currMove.pop_back();
        if (curr == source) {
            pathToSource = currPath;
            moveToSource = currMove;
        }
        else if (curr == dest) {
            pathToDest = currPath;
            moveToDest = currMove;
        }
        currMove.push_back('R');
        traverse(root->right, pathToSource, pathToDest, currPath, moveToSource, moveToDest, currMove, source, dest);
        currMove.pop_back();
        currPath.pop_back();
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        // GetPath

        vector<int> pathToSource, pathToDest, currPath;
        string currMove = "", moveToDest = "", moveToSource = "";

        traverse(root, pathToSource, pathToDest, currPath, moveToSource, moveToDest, currMove, startValue, destValue);

        int lcs = pathToSource[0], ind = 0;
        for(int i = 1; i < pathToSource.size() && i < pathToDest.size(); ++i){
            if (pathToDest[i] == pathToSource[i]) {
                lcs = pathToDest[i];
                ind = i;
            }
            else {
                break;
            }
        }

        string ans = "";
        for(int i = ind; i < moveToSource.size(); ++i) {
            ans += 'U';
        }
        for(int i = ind; i < moveToDest.size(); ++i) {
            ans += moveToDest[i];
        }

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