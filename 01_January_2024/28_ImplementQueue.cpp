// https://leetcode.com/problems/implement-queue-using-stacks/?envType=daily-question&envId=2024-01-29

#include <bits/stdc++.h>
using namespace std ;

class MyQueue {
private:
    stack<int> s1, s2;
public:
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        peek();
        int top = s2.top();
        s2.pop();
        return top;
    }
    
    int peek() {
        if(s2.empty())
            while(!s1.empty()) s2.push(s1.top()), s1.pop();
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main () {
    
    return 0;
}