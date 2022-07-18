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

Node* deleteTail(Node* head) {
    if (head == NULL) 
        return head;
        
    if (head -> next == NULL) {
        delete head;
        return NULL;
    }
        
    Node* curr = head;
    while (curr -> next != NULL) 
        curr = curr -> next;
    
    curr -> prev -> next = NULL;
    delete curr;
    return head;
}

int main() {
	Node* head = new Node(40);
	Node* temp1 = new Node(10);
	head -> next = temp1;
	temp1 -> prev = head;
	Node* temp2 = new Node(20);
	temp1 -> next = temp2;
	temp2 -> prev = temp1;
	head = deleteTail(head);
	return 0;
}
