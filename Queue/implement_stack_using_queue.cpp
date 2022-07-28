#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue<int> q;
    int size;
    
    void insertIntoQueue(queue<int>& q) {
        for (int i = 0; i < q.size() - 1; ++i) {
            q.push(q.front());
            q.pop();
        }
    }
    
    MyStack() {
        size = 0;
    }
    
    void push(int x) {
        ++size;
        q.push(x);
        insertIntoQueue(q);
    }
    
    int pop() {
        --size;
        int first_element = q.front();
        q.pop();
        return first_element;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return size == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */