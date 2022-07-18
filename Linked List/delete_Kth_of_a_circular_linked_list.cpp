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

Node* deleteHead(Node* head) {
    if (head == NULL)
        return NULL;
        
    if (head -> next == head) {
        delete head;
        return NULL;
    }
    
    head -> data = head -> next -> data;
    Node* temp = head -> next;
    head -> next = head -> next -> next;
    delete temp;
    return head;
}

Node* insertAtBeginning(Node* head, int value) {
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

Node* deleteKthNode(Node* head, int k) {
    if (head == NULL)
        return head;
    if (k == 1)
        return deleteHead(head);
        
    Node* curr = head;
    for (int i = 0; i < k - 2; ++i) 
        curr = curr -> next;
        
    Node* temp = curr -> next;
    curr -> next = curr -> next -> next;
    delete temp;
    return head;
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
	head = deleteKthNode(head, 2);
	printCircularList(head);
	return 0;
}
