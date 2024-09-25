// https://leetcode.com/problems/sum-of-prefix-scores-of-strings/?envType=daily-question&envId=2024-09-25

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

struct TrieNode{
    unordered_map<char,TrieNode*> children;
    int countPostEOW;
    TrieNode(){
        countPostEOW=0;
    }
};

class Solution {
    TrieNode* root;

    void constructTrie(TrieNode* root,int index,string &word){
        if(index==word.length()) return;
        auto &children= root->children;
        if(children.find(word[index])==children.end()){
            children[word[index]]= new TrieNode();
        }
        TrieNode* &node= children[word[index]];
        if(index==word.length()-1) node->countPostEOW++;
        constructTrie(node,index+1,word);
    }

    int updateCount(TrieNode* root){
        if(!root) return 0;
        auto &children= root->children;
        int res=0;
        for(auto &[key,child]:children){
            if(child){
                child->countPostEOW+= updateCount(child);
                res+= child->countPostEOW;
            }
        }
        return res;
    }

    int search(TrieNode* root,int i,string &word){
        if(i==word.length()) return 0;
        auto &children= root->children;
        if(children.find(word[i])==children.end())return 0;
        TrieNode* &node= children[word[i]];
        return node->countPostEOW+ search(node,i+1,word); 
    }

public:
    vector<int> sumPrefixScores(vector<string>& words) {
        root= new TrieNode();
        for(auto &word:words){
            constructTrie(root,0,word);
        }
        updateCount(root);
        vector<int> res;
        int x;
        for(auto &word:words){

            x= search(root,0,word)-(root->countPostEOW);
            res.push_back(x);
        }
        return res;
    }
};

int main () {
    
    return 0;
}
