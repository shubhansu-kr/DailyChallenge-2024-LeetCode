// https://leetcode.com/problems/design-a-stack-with-increment-operation/?envType=daily-question&envId=2024-09-30

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class CustomStack
{
    int max, top;
    int *Arr;

public:
    CustomStack(int maxSize)
    {
        max = maxSize;
        Arr = new int[max];
        top = -1;
    }

    void push(int x)
    {
        if (top == max - 1)
        {
            return;
        }
        else
        {
            top++;
            Arr[top] = x;
        }
    }

    int pop()
    {
        if (top == -1)
        {
            return top;
        }
        --top;
        return Arr[top + 1];
    }

    void increment(int k, int val)
    {
        for (int i = 0; i <= top; i++)
        {
            if (i == k)
            {
                break;
            }
            Arr[i] += val;
        }
    }
};

int main () {
    
    return 0;
}
