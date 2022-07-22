#include <bits/stdc++.h>
using namespace std;

struct myStack {
    int* arr;
    int capacity;
    int top;
    
    myStack(int length) {
        capacity = length;
        arr = new int[capacity];
        top = -1;
    }
    
    void push(int element) {
        ++top;
        arr[top] = element;
    }
    
    int pop() {
        int res = arr[top];
        --top;
        return res;
    }
    
    int peek() {
        return arr[top];
    }
    
    int size() {
        return top + 1;
    }
    
    bool isEmpty() {
        return top == -1;
    }
};

int main() {
	myStack s(5);
	s.push(1);
	s.push(4);
	cout << s.pop() << endl;
	cout << s.peek() << endl;
	return 0;
}
