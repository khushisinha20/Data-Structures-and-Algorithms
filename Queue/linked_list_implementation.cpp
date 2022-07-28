#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

struct Queue {
    Node* front;
    Node* rear;
    int size = 0;
    Queue() {
        front = NULL;
        rear = NULL;
        size = 0;
    }
    
    bool isEmpty() {
        return front == NULL;
    }
    
    void enqueue(int val) {
        Node* node = new Node(val);
        if (front == NULL) {
            front = node;
            rear = node;
            return;
        }
        
        rear -> next = node;
        rear = node;
        ++size;
    }
    
    void dequeue() {
        Node* temp = front;
        if (front == NULL)
            return;
        front = front -> next;
        if (front == NULL) {
            rear = NULL;
            return;
        }
        delete temp;
        --size;
    }
    
    int top() {
        if (rear == NULL)
            return -1;
        return rear -> data;
    }
};

int main() {
    Queue q;
    q.enqueue(4);
    q.enqueue(14);
    q.enqueue(24);
    q.dequeue();
    q.dequeue();
    q.enqueue(34);
    return 0;
}