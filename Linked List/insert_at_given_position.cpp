//Insert at given position 

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

Node* insertAtPosition(Node* head, int value, int position) {
    if (position == NULL) {
        Node* temp = new Node(value);
        temp -> next = head;
        return temp;
    }
    
    Node* curr = head;
    for (int i = 1; i <= position - 2; ++i) {
        curr = curr -> next;
    }
    
    if (curr == NULL)
        return head;
    
    Node* temp = new Node(value);
    temp -> next = curr -> next;
    curr -> next = temp;
    return head;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head -> data << " ";
        head = head -> next;
    }
}

int main() {
    Node* head = new Node(10);  
    head -> next = new Node(20);
    head -> next -> next = new Node(30);
    head -> next -> next -> next = new Node(40);
    insertAtPosition(head, 25, 3);
    printList(head);
    return 0;
}