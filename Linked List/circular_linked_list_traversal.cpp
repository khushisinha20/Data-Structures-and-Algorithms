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

void printCircularList(Node* head) {
    if (head == NULL) 
        return;
        
    Node* curr = head;    
        
    do {
        cout << (curr -> data) << " ";
        curr = curr -> next;
    } while (curr != head);
}

int main() {
	Node* head = new Node(10);
	Node* temp1 = new Node(20);
	head -> next = temp1;
	Node* temp2 = new Node(30);
	temp1 -> next = temp2;
	temp2 -> next = head;
	printCircularList(head);
	return 0;
}