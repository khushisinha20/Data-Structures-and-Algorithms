//leetcode.com/problems/design-circular-deque/

#include <bits/stdc++.h>
using namespace std;

class MyCircularDeque {
public:
    vector<int> deque;
    int front;
    int rear;
    int capacity;
    
    MyCircularDeque(int k) {
        capacity = k;
        deque.resize(capacity);
        front = -1;
        rear = -1;
    }
    
    bool insertFront(int value) {
        if (isFull())
            return false;
        
        if (isEmpty())
            front = rear = 0;
        else
            front = (front - 1 + capacity) % capacity;
        deque[front] = value;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull())
            return false;
        
        if (isEmpty())
            front = rear = 0;
        else
            rear = (rear + 1) % capacity;
        
        deque[rear] = value;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty())
            return false;
        
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % capacity;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty())
            return false;
        
        if (front == rear)
            front = rear = -1;
        else
            rear = (rear - 1 + capacity) % capacity;
        return true;
    }
    
    int getFront() {
        return isEmpty() ? -1 : deque[front];
    }
    
    int getRear() {
        return isEmpty() ? -1 : deque[rear];
    }
    
    bool isEmpty() {
        return front == -1;
    }
    
    bool isFull() {
        return (rear + 1) % capacity == front;
    }
};