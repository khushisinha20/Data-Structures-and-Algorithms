#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next = NULL;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

struct myStack {
    Node* head;
    int length;
    
    myStack() {
        head = NULL;
        length = 0;
    }
    
    void push(int val) {
        Node* temp = new Node(val);
        temp -> next = head;
        ++length;
        head = temp;
    }
    
    int pop() {
        int res = head -> data;
        Node* temp = head;
        head = head -> next;
        delete temp;
        ++length;
        return res;
    }
    
    int peek() {
        return head -> data;
    }
    
    int size() {
        return length;
    }
    
    bool isEmpty() {
        return head == NULL;
    }
};

int main() {
	myStack s;
	s.push(1);
	s.push(4);
	cout << s.pop() << endl;
	cout << s.peek() << endl;
	return 0;
}