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

Node* reverseDoublyLinkedList(Node* head) {
    if (head == NULL || head -> next == NULL)
        return head;
        
    Node* curr = head;
    Node* previous_node = curr -> prev;
    while (curr != head) {
        previous_node = curr -> prev;
        curr -> prev = curr -> next;
        curr -> next = previous_node;
        curr = curr -> prev;
    }
    return previous_node -> prev;
}

int main() {
	Node* head = new Node(40);
	Node* temp1 = new Node(10);
	head -> next = temp1;
	temp1 -> prev = head;
	Node* temp2 = new Node(20);
	temp1 -> next = temp2;
	temp2 -> prev = temp1;
	return 0;
}
