#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int value) {
        data = value;
        prev = NULL;
        next = NULL;
    }
};

Node* insertAtEnd(Node* head, int value) {
    Node* temp = new Node(value);
    if (head == NULL)
        return temp;
        
    Node* curr = head;
    while (curr -> next != NULL) {
        curr = curr -> next;
    }
    curr -> next = temp;
    temp -> prev = curr;
    return head;
}

int main() {
	Node* head = NULL;
	head = insertAtEnd(head, 10);
	head = insertAtEnd(head, 20);
	head = insertAtEnd(head, 30);
	return 0;
}
