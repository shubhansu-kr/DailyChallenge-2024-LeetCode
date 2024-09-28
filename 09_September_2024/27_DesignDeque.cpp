// https://leetcode.com/problems/design-circular-deque/?envType=daily-question&envId=2024-09-28

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

struct node
{
    int val;
    node *next;
    node() : val(0), next(nullptr) {}
    node(int x) : val(x), next(nullptr) {}
    node(int x, node *next) : val(x), next(next) {}
};

class MyCircularDeque {
int maxSize;
    int count;
    node *front, *rear;

public:
    MyCircularDeque(int k) : maxSize(k)
    {
        count = 0;
        front = rear = nullptr;
    }

    bool insertFront(int value)
    {
        if (count == maxSize)
        {
            return false;
        }
        node *temp = new node(value, front);
        front = temp;
        if (count == 0)
        {
            rear = front;
        }
        count++;
        return true;
    }

    bool insertLast(int value)
    {
        if (count == maxSize)
        {
            return false;
        }
        node *temp = new node(value);
        if (count == 0)
        {
            front = rear = temp;
            count++;
            return true;
        }
        rear->next = temp;
        rear = temp;
        count++;
        return true;
    }

    bool deleteFront()
    {
        if (count == 0)
        {
            return false;
        }
        node *temp = front;
        front = front->next;
        delete (temp);
        count--;
        if (count == 0)
        {
            rear = front;
        }
        return true;
    }

    bool deleteLast()
    {
        if (count == 0)
        {
            return false;
        }
        node *temp = front;
        if (count == 1)
        {
            front = rear = NULL;
            delete (temp);
            count--;
            return true;
        }
        while (temp->next != rear)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        delete (rear);
        rear = temp;
        count--;
        return true;
    }

    int getFront()
    {
        if (count == 0)
        {
            return -1;
        }
        return front->val;
    }

    int getRear()
    {
        if (count == 0)
        {
            return -1;
        }
        return rear->val;
    }

    bool isEmpty()
    {
        if (count == 0)
        {
            return true;
        }
        return false;
    }

    bool isFull()
    {
        if (count == maxSize)
        {
            return true;
        }
        return false;
    }
};

int main () {
    
    return 0;
}
