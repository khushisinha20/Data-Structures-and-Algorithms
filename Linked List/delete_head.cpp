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
    
    Node* temp = head -> next;
    delete head;
    return temp;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head -> data << " ";
        head = head -> next;
    }
}

int main() {
    Node* head = NULL;
    head = new Node(10);
    head -> next = new Node(20);
    head -> next -> next = new Node(30);
    head = deleteHead(head);
    printList(head);
    return 0;
}