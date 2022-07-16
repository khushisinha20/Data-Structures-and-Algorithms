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

Node* insertAtBegin(Node* head, int value) {
    Node* temp = new Node(value);
    temp -> next = head;
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
    head = insertAtBegin(head, 10);
    head = insertAtBegin(head, 20);
    head = insertAtBegin(head, 30);
    printList(head);
    return 0;
}