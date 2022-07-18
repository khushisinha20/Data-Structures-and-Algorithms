#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = NULL;
    }
};

Node* insertAtEnd(Node* head, int value) {
    Node* temp = new Node(value);
    
    if (head == NULL) {
        temp -> next = head;
        return temp;
    }
    
    int temp_value = temp -> data;
    temp -> next = head -> next;
    head -> next = temp;
    temp -> data= head -> data;
    head -> data = value; 
    
    return temp;
}

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
	head = insertAtEnd(head, 5);
	printCircularList(head);
	return 0;
}
