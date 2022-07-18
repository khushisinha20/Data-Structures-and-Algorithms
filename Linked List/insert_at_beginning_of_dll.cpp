#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int value) {
        data = value;
        prev = NULL;
        next = NULL;
    }
};

Node* insertAtBeginning(Node* head, int value) {
    Node* temp = new Node(value);
    temp -> next = head;
    if (head != NULL)
        head -> prev = temp;
    return temp;
}

int main() {
	Node* head = new Node(10);
	Node* temp1 = new Node(20);
	Node* temp2 = new Node(30);
	head -> next = temp1;
	temp1 -> prev = head;
	temp1 -> next = temp2;
	temp2 -> prev = temp1;
	return 0;
}