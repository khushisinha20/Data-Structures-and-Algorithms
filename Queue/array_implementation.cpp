#include <bits/stdc++.h>
using namespace std;

struct Queue {
    int capacity;
    int size;
    int front;
    int *arr;
    
    Queue(int max_capacity) {
        arr = new int[max_capacity];
        capacity = max_capacity;
        front = 0;
        size = 0;
    }
    
    bool isFull() {
        return capacity == size;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    int getFront() {
        if (isEmpty())
            return -1;
        return front;
    }
    
    int getRear() {
        if (isEmpty())
            return -1;
        return (front + size - 1) % capacity;
    }
    
    void enqueue(int val) {
        if (isFull())
            return;
        int rear = getRear();
        rear = (rear + 1) % capacity;
        arr[rear] = val;
        ++size;
    }
    
    void dequeue() {
        if (isFull())
            return;
        int front = (front + 1) % capacity;
        --size;
    }
    
    int top() {
        if (isEmpty())
            return -1;
        return arr[front];
    }
};

int main() {
    Queue q(5);
    q.enqueue(4);
    q.enqueue(14);
    q.enqueue(24);
    q.dequeue();
    q.dequeue();
    q.enqueue(34);
    while (!q.isEmpty()) {
        cout << q.top() << '\n';
        q.dequeue();
    } 
    return 0;
}