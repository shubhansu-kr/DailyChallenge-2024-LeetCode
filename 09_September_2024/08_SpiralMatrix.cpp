// https://leetcode.com/problems/spiral-matrix-iv/?envType=daily-question&envId=2024-09-09

#include <bits/stdc++.h>
using namespace std ;

struct ListNode {
    int val;
    ListNode * next;
    ListNode():val(0), next(nullptr){}
    ListNode(int val):val(val), next(nullptr){}
    ListNode(int val, ListNode *next):val(val), next(next){}
};

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
         ios_base :: sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int a = 0, b = 0;
        int k = m-1, c = n-1;
        vector<vector<int>> ans(m, vector<int>(n, -1));

        while(head){
            for(int i = b; i <= c && head; i++){
                ans[a][i] = head -> val;
                head = head -> next;
            }
            a++;
            for(int i = a; i <= k && head; i++){
                ans[i][c] = head -> val;
                head = head -> next;
            }
            c--;
            for(int i = c; i >= b && head; i--){
                ans[k][i] = head -> val;
                head = head -> next;
            }
            k--;
            for(int i = k; i >= a && head; i--){
                ans[i][b] = head -> val;
                head = head -> next; 
            }
            b++;
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