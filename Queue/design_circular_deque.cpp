//leetcode.com/problems/design-circular-queue/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int val) {
        this -> val = val;
        next = NULL;
    }
};

class MyCircularQueue {
public:
    int capacity = 0;
    int size = 0;
    Node* head = NULL;
    Node* tail = NULL;
    
    MyCircularQueue(int k) {
        capacity = k;
        size = 0;
    }
    
    bool enQueue(int value) {
        if (size == capacity)
            return false;
        if (!head) {
            head = new Node(value);
            tail = head;
        } else {
            tail -> next = new Node(value);
            tail = tail -> next;
        }
        ++size;
        return true;
    }
    
    bool deQueue() {
        if (size == 0)
            return false;
        Node* curr = head -> next;
        delete head;
        head = curr;
        --size;
        return true;
    }
    
    int Front() {
        if (size == 0)
            return -1;
        return head -> val;
    }
    
    int Rear() {
        if (size == 0)
            return -1;
        return tail -> val;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};
